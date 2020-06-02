from sys import argv, exit
import csv
import sqlite3

if len(argv) != 2:
    print("GETOUT")
    exit(1)

if ".csv" not in argv[1]:
    print("GETOUT")
    exit(2)

def connect_db(name):
    return sqlite3.connect(name)

conn = connect_db("students.db")
c = conn.cursor()

index = 1
with open(argv[1], "r") as characters:
    reader = csv.DictReader(characters)

    for row in reader:
        first = row["name"].split()[0]
        house = row["house"]
        birth = row["birth"]
        print(row["name"].split(), row["house"], row["birth"])
        if len(row["name"].split()) < 3:
            middle = None
            last = row["name"].split()[1]
            c.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", (first, middle, last, house, birth))
        elif len(row["name"].split()) == 3:
            middle = row["name"].split()[1]
            last = row["name"].split()[2]
            c.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", (first, middle, last, house, birth))

# for i in c.execute("SELECT * FROM students"):
#     print(i)

conn.commit()
conn.close()

