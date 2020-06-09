#! /usr/bin/python

a = float(input())
b = float(input())
op = str(input())

if op == "div" or op == "mod" or op == "/":
	if b == 0:
		print("Division by 0!")
	elif op == "mod":
		print(int(a % b))
	elif op == "div":
		print(int(a / b))
	else:
		print(a / b)
elif op == "+":
	print(a + b)
elif op == "-":
	print(a - b)
elif op == "*":
	print(a * b)
else:
	print(a ** b)
'''elif op == "pow":
	print(a ** b)
else:
	print("An unexpected operation!")'''

