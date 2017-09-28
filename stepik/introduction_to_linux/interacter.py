#!/usr/bin/python

import sys

while True:
    print("Hi, what is your name?")
    line = sys.stdin.readline()
    line = line.strip()
    if not line:
        print("Bye!")
        break
    if line[0].islower():
        sys.stderr.write("You made a mistake! I will capitalize your name!\n")
    print("Nice to meet you, " + line[0].upper() + line[1:] + "!")

