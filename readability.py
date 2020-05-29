# Implementation of Readability in Python by MonolithOfficial
from cs50 import get_string

# First we define a function which will analyze the input and according to its metrics will return it's respective Grade.


def col_liau(text):
    l_count = 0
    w_count = 1
    s_count = 0
    for i in text:
        if i.lower().isalpha():
            l_count += 1
        if i == " ":
            w_count += 1
        if i == "." or i == "?" or i == "!":
            s_count += 1

    l = float(l_count / w_count) * 100.0
    s = float(s_count / w_count) * 100.0

    return (0.0588 * l) - (0.296 * s) - 15.8


# Getting user's input
user_inp = get_string("Text: ")

# Handling cases with Grade levels below or above given interval.
if round(col_liau(user_inp)) < 1:
    print("Before Grade 1")

elif round(col_liau(user_inp)) > 16:
    print("Grade 16+")
else:
    print(f"Grade {round(col_liau(user_inp))}")