#! /bin/bash

counter () # takes one argument
{
	local let "c1+=$1"
	let "c2+=${1}*2"
	
}

i=0
while [ $i -lt 10 ]
do
	let "i = i + 1"
	echo "counter $i"
	counter $i
done

echo "counters are $c1 and $c2"
