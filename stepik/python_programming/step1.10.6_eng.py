#! /usr/bin/python

y = int(input())

ly = False #Leap year.
if y % 4 == 0:
	if y % 100 == 0:
		if y % 400 == 0:
			ly = True
	else:
		ly = True
if ly:
	print('Leap year')
else:
	print('Ordinary year')
