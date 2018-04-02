#! /usr/bin/python

a = int(input())
b = int(input())
c = int(input())

p = (a + b + c) / 2

print( (p * (p - a) * (p - b) * (p - c)) ** .5 )
