# Implementation of Mario in Python

from sys import exit
from cs50 import get_int

height = get_int("Height: ")

while height not in range(1, 9):
    height = get_int("Height: ")

x = 0
for i in range(height):
    x += 1
    print((" " * (height - x)) + ("#" * x) + "  " + ("#" * x))