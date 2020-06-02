from sys import argv, exit
import sqlite3

# Making sure the number of commandline arguments is correct
if len(argv) != 2:
    print("GETOUT")
    exit(1)

houses = ["gryffindor", "slytherin", "ravenclaw", "hufflepuff"]
if argv[1].lower() not in houses:
    print("GETOUT")
    exit(1)

# Connecting to the database
conn = sqlite3.connect("students.db")
c = conn.cursor()
# Storing input in a variable for case manipulation purposes
house_inp = argv[1].lower()

# Inerating over records and printing them out in formatted form
for row in c.execute("SELECT * FROM students WHERE LOWER(house) = ? ORDER BY last", (house_inp, )):
    if row[2] == None:
        print("{0} {1}, born in {2}".format(row[1], row[3], row[5]))
    else:
        print("{0} {1} {2}, born in {3}".format(row[1], row[2], row[3], row[5]))