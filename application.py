import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session, flash
from flask_session import Session
from tempfile import mkdtemp
from datetime import datetime
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    rows = db.execute(
        "SELECT id, name, price, symbol, time, SUM(qty) FROM user_info WHERE id = :id GROUP BY symbol", id=session["user_id"])
    print(rows)
    if "rows" not in session:
        session["rows"] = rows

    total_in_assets = 0
    for row in rows:
        total_in_assets += float(row["price"]) * int(row["SUM(qty)"])

    # Show portfolio of stocks
    # Searching the database for records with id of current user.
    user_cash_sel = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])

    # Retrieving curent balance
    user_cash = float(user_cash_sel[0]["cash"])
    formatted_cash = format(user_cash, ',.2f')
    total_cash = total_in_assets + user_cash
    formatted_total_cash = format(round(total_cash, 2), ',.2f')
    # print(formatted_cash)
    return render_template("index.html", user_cash=formatted_cash, rows=session["rows"], total=total_cash)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "GET":
        return render_template("buy.html")
    else:
        # print(lookup(request.form.get("symbol")))
        api_data = lookup(request.form.get("symbol"))
        if api_data == None:
            return apology("Stock not found!")
        now = datetime.now()
        dt_string = now.strftime("%d/%m/%Y %H:%M:%S")

        # Checking if the user has enough money to buy desired amount of stocks.
        if (api_data["price"] * int(request.form.get("shares"))) > db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])[0]["cash"]:
            return apology("NOT ENOUGH DOUG LLOYD")
        else:
            # User's balance before the purchase
            user_cash_bf = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])

            # Updating user's balance
            db.execute("UPDATE users SET cash = :new_cash WHERE id = :id",
                       new_cash=user_cash_bf[0]["cash"] - (api_data["price"] * int(request.form.get("shares"))), id=session["user_id"])

            # Logging purchase details

            db.execute("INSERT INTO user_info (id, name, price, symbol, time, qty) VALUES (:id, :name, :price, :symbol, :time, :qty)",
                       id=session['user_id'], name=api_data["name"], price=api_data["price"], symbol=api_data["symbol"], time=dt_string, qty=int(request.form.get("shares")))

            rows = db.execute(
                "SELECT id, name, price, symbol, time, SUM(qty) FROM user_info WHERE id = :id GROUP BY symbol", id=session["user_id"])
            session["rows"] = rows
            # print(api_data["symbol"])
            flash('Bought!')
            return redirect("/")
            # return render_template("index.html", rows = session["rows"], user_cash = user_cash_bf[0]["cash"] - (api_data["price"] * int(request.form.get("shares"))), flash = get_flashed_message)


@app.route("/history")
@login_required
def history():
    rows = db.execute("SELECT * FROM user_info WHERE id = :id", id=session["user_id"])
    return render_template("history.html", rows=rows)


@app.route("/change_pass", methods=["GET", "POST"])
@login_required
def change_pass():
    if request.method == "GET":
        return render_template("change_pass.html")
    else:
        old_pass = db.execute("SELECT hash FROM users WHERE id = :id", id=session["user_id"])
        new_pass = request.form.get("new")
        new_conf = request.form.get("new_conf")
        if check_password_hash(old_pass[0]["hash"], request.form.get("old")) and new_pass == new_conf:
            new_pass_hash = generate_password_hash(new_pass)
            db.execute("UPDATE users SET hash = :hash_pass WHERE id = :id", hash_pass=new_pass_hash, id=session["user_id"])
            flash('Password changed successfully!')
            return redirect("/login")
        else:
            return apology("Please fill the form correctly")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")
    else:
        api_response = lookup(request.form.get("symbol"))
        if api_response == None:
            return apology("Stock not Found!")

        return render_template("quoted.html", api_post=api_response)


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "GET":
        return render_template("register.html")

    else:
        username = request.form.get("username")
        if not username:
            return apology("You must provide a username!")
        password = generate_password_hash(request.form.get("password"))
        if not password:
            return apology("You must provide a password!")
        con_pass = generate_password_hash(request.form.get("con_password"))
        if request.form.get("con_password") != request.form.get("password"):
            return apology("Please confirm your password!")
        # print(len(password), len(con_pass))
        occupied_username = db.execute("SELECT username FROM users WHERE username = :username", username=username)
        if occupied_username:
            return apology(f"{username} is already taken!")
        # return password, con_pass
        db.execute("INSERT INTO users (username, hash) VALUES(:username, :hash)", username=username, hash=password)
        return redirect("/login")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    if request.method == "GET":
        opts = db.execute("SELECT DISTINCT symbol FROM user_info WHERE id = :id", id=session["user_id"])
        return render_template("sell.html", opts=opts)
    else:
        amount_of_requested_shares = db.execute(
            "SELECT SUM(qty) FROM user_info WHERE id = :id AND symbol = :symbol", id=session["user_id"], symbol=request.form.get("symbol"))
        if int(request.form.get("shares")) > int(amount_of_requested_shares[0]["SUM(qty)"]):
            return apology("NOT ENOUGH SHARES")
        else:
            now = datetime.now()
            dt_string = now.strftime("%d/%m/%Y %H:%M:%S")
            # new_amount_of_shares = int(amount_of_requested_shares[0]["SUM(qty)"]) - int(request.form.get("shares"))
            # print(amount_of_requested_shares[0]["SUM(qty)"])
            api_lookup = lookup(request.form.get("symbol"))
            api_cost = api_lookup["price"]
            cash_from_sell = int(request.form.get("shares")) * float(api_cost)
            sell = int(request.form.get("shares")) * (-1)

            user_balance_sel = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])
            user_balance = float(user_balance_sel[0]["cash"])

            new_cash = user_balance + cash_from_sell

            print(user_balance, cash_from_sell)

            db.execute("UPDATE users SET cash = :new_cash WHERE id = :id", id=session["user_id"], new_cash=new_cash)

            db.execute("INSERT INTO user_info (id, name, price, symbol, time, qty) VALUES (:id, :name, :price, :symbol, :time, :qty)",
                       id=session["user_id"], name=api_lookup["name"], price=api_lookup["price"], symbol=request.form.get("symbol"), time=dt_string, qty=sell)

            rows = db.execute(
                "SELECT id, name, price, symbol, time, SUM(qty) FROM user_info WHERE id = :id GROUP BY symbol", id=session["user_id"])
            session["rows"] = rows
            flash('Sold!')
            return redirect("/")


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
