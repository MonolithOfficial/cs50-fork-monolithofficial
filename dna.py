import csv
from cs50 import get_string
from sys import argv, exit
import re
# from funcs import agatc, ttttttct, aatg, tctag, gata, tatc, gaaa, tctg
from collections import defaultdict


def agatc(text):
    occurences_len = []
    pattern = re.compile(r"(AGATC)+")
    matches = pattern.finditer(text)

    for match in matches:
        # print(match)
        occurences_len.append(len(match[0]))
    # print(occurences_len)
    if len(occurences_len) == 0:
        return 0
    # print(int((max(occurences_len) / 5)))
    return int((max(occurences_len) / 5))


def ttttttct(text):
    occurences_len = []
    pattern = re.compile(r"(TTTTTTCT)+")
    matches = pattern.finditer(text)

    for match in matches:
        # print(match)
        occurences_len.append(len(match[0]))
    # print(occurences_len)
    if len(occurences_len) == 0:
        return 0
    # print(int((max(occurences_len) / 8)))
    return int((max(occurences_len) / 8))


def aatg(text):
    occurences_len = []
    pattern = re.compile(r"(AATG)+")
    matches = pattern.finditer(text)

    for match in matches:
        # print(match)
        occurences_len.append(len(match[0]))
    # print(occurences_len)
    if len(occurences_len) == 0:
        return 0
    # print(int((max(occurences_len) / 4)))
    return int((max(occurences_len) / 4))


def tctag(text):
    occurences_len = []
    pattern = re.compile(r"(TCTAG)+")
    matches = pattern.finditer(text)

    for match in matches:
        # print(match)
        occurences_len.append(len(match[0]))
    # print(occurences_len)
    if len(occurences_len) == 0:
        return 0
    # print(int((max(occurences_len) / 5)))
    return int((max(occurences_len) / 5))


def gata(text):
    occurences_len = []
    pattern = re.compile(r"(GATA)+")
    matches = pattern.finditer(text)

    for match in matches:
        # print(match)
        occurences_len.append(len(match[0]))
    # print(occurences_len)
    if len(occurences_len) == 0:
        return 0
    # print(int((max(occurences_len) / 4)))
    return int((max(occurences_len) / 4))


def tatc(text):
    occurences_len = []
    pattern = re.compile(r"(TATC)+")
    matches = pattern.finditer(text)

    for match in matches:
        # print(match)
        occurences_len.append(len(match[0]))
    # print(occurences_len)
    if len(occurences_len) == 0:
        return 0
    # print(int((max(occurences_len) / 4)))
    return int((max(occurences_len) / 4))


def gaaa(text):
    occurences_len = []
    pattern = re.compile(r"(GAAA)+")
    matches = pattern.finditer(text)

    for match in matches:
        # print(match)
        occurences_len.append(len(match[0]))
    # print(occurences_len)
    if len(occurences_len) == 0:
        return 0
    # print(int((max(occurences_len) / 4)))
    return int((max(occurences_len) / 4))


def tctg(text):
    occurences_len = []
    pattern = re.compile(r"(TCTG)+")
    matches = pattern.finditer(text)

    for match in matches:
        # print(match)
        occurences_len.append(len(match[0]))
    # print(occurences_len)
    if len(occurences_len) == 0:
        return 0
    # print(int((max(occurences_len) / 4)))
    return int((max(occurences_len) / 4))


# Making sure the number of arguments is indeed 3
if len(argv) != 3:
    print("More args")
    exit(1)

# Making sure the file the user is trying to open via second command line is a .csv
if ".csv" not in argv[1] or ".txt" not in argv[2]:
    print("Go away")
    exit(2)

# This is the list where dictionaries will be stored with corresponding key/value pairs.
list_of_dna = []
# Opening the .csv file
csv_file_open = open(f"{argv[1]}", "r")
# Each row will hold a key, then values will be added via for loop
rows = []

for row in csv_file_open:
    rows.append(row.rstrip('\n').split(","))
keys = rows[0]
for values in rows[1:]:
    list_of_dna.append(dict(zip(keys, values)))

# Opening the sequence .txt file
dna_file_open = open(f"{argv[2]}", "r")
dna_file_read = dna_file_open.read()

# These are the functions I made to detect longest STRs for all given patterns.
agatc = agatc(dna_file_read)
ttttttct = ttttttct(dna_file_read)
aatg = aatg(dna_file_read)
tctag = tctag(dna_file_read)
gata = gata(dna_file_read)
tatc = tatc(dna_file_read)
gaaa = gaaa(dna_file_read)
tctg = tctg(dna_file_read)

# print(agatc, ttttttct, aatg, tctag, gata, tatc, gaaa, tctg)

# print(f"{agatc(dna_file_read)},{aatg(dna_file_read)},{tatc(dna_file_read)}")
# if f"{agatc(dna_file_read)},{ttttttct(dna_file_read)},{aatg(dna_file_read)},{tctag(dna_file_read)},{gata(dna_file_read)},{tatc(dna_file_read)},{gaaa(dna_file_read)},{tctag(dna_file_read)}" in csv_file_read:
#     print("true")
# if "15,49,38,5,14,44,14,12" in csv_file_read:
#     print("true")
# if f"{agatc(dna_file_read)},{aatg(dna_file_read)},{tatc(dna_file_read)}" in csv_file_read:
#     print("true")
# else:
#     print("No match")

if argv[1] == "databases/large.csv":
    i = 0
    match_count_lrg = 0
    while i < len(list_of_dna):
        if list_of_dna[i]["AGATC"] == str(agatc) and list_of_dna[i]["TTTTTTCT"] == str(ttttttct) and list_of_dna[i]["AATG"] == str(aatg) and list_of_dna[i]["TCTAG"] == str(tctag) and list_of_dna[i]["GATA"] == str(gata) and list_of_dna[i]["TATC"] == str(tatc) and list_of_dna[i]["GAAA"] == str(gaaa) and list_of_dna[i]["TCTG"] == str(tctg):
            print(list_of_dna[i]["name"])
            match_count_lrg += 1
        i += 1

    if match_count_lrg == 0:
        print("No match")

elif argv[1] == "databases/small.csv":
    k = 0
    match_count_sml = 0
    while k < len(list_of_dna):
        if list_of_dna[k]["AGATC"] == str(agatc) and list_of_dna[k]["AATG"] == str(aatg) and list_of_dna[k]["TATC"] == str(tatc):
            print(list_of_dna[k]["name"])
            match_count_sml += 1

        k += 1
    if match_count_sml == 0:
        print("No match")