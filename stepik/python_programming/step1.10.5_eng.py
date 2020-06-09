#! /usr/bin/python

a = int(input())
b = int(input())
h = int(input())

if a <= h <= b:
    print('This is normal.')
elif h < a:
	print('Undersleeping.')
else:
	print('Oversleeping.')
