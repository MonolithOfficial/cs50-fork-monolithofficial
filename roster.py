from sys import argv, exit
import sqlite3

if len(argv) != 2:
    print("GETOUT")
    exit(1)

houses = ["gryffindor", "slytherin", "ravenclaw", "hufflepuff"]
if argv[1].lower() not in houses:
    print("GETOUT")
    exit(1)

conn = sqlite3.connect("students.db")
c = conn.cursor()
house_inp = argv[1].lower()

for row in c.execute("SELECT * FROM students WHERE LOWER(house) = ? ORDER BY last", (house_inp, )):
    if row[2] == None:
        print("{0} {1}, born in {2}".format(row[1], row[3], row[5]))
    else:
        print("{0} {1} {2}, born in {3}".format(row[1], row[2], row[3], row[5]))



