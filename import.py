from sys import argv, exit
import csv
import sqlite3

# Making sure the number of commandline arguments is correct
if len(argv) != 2:
    print("GETOUT")
    exit(1)

# Making sure the first commandline argument contains ".csv" file extension
if ".csv" not in argv[1]:
    print("GETOUT")
    exit(2)

# Connecting to the database via function


def connect_db(name):
    return sqlite3.connect(name)


conn = connect_db("students.db")
c = conn.cursor()

# Opening the .csv file
with open(argv[1], "r") as characters:
    reader = csv.DictReader(characters)

    # Iterating over the rows
    for row in reader:
        # Splitting "name" to get firs middle and last names
        first = row["name"].split()[0]
        house = row["house"]
        birth = row["birth"]
        print(row["name"].split(), row["house"], row["birth"])
        # Inserting rows into the database
        if len(row["name"].split()) < 3:
            middle = None
            last = row["name"].split()[1]
            c.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                      (first, middle, last, house, birth))
        elif len(row["name"].split()) == 3:
            middle = row["name"].split()[1]
            last = row["name"].split()[2]
            c.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                      (first, middle, last, house, birth))

# Commiting and closing the database
conn.commit()
conn.close()

