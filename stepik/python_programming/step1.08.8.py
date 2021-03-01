#! /usr/bin/python

x = int(input()) #The duration in minutes to sleep.
h = int(input()) #The hour to go to bed.
m = int(input()) #The minute to go to bed.

ha = int(h + x / 60) #The initial estimate of the alarm hour.
ma = int(m + x % 60) #The initial estimate of the alarm minute. 

ha += ma / 60 #The adjustment of the alarm hour for the minutes that may overlapping 60-minute threshold.
ma %= 60 #The adjustment of the alarm minute for the minutes overlapping 60-minute threshold.

print(int(ha))
print(int(ma))
