#! /bin/bash

while [ 1 ]
do

	echo "enter your name:"
	read name

	if [[ -z $name ]]
	then
		echo "bye"
		break
	else
		echo "enter your age:"
		read age

		if [[ $age == 0 ]]
		then
			echo "bye"
			break
		else
			if [[ $age -le 16 ]]
			then
				group="child"
			elif [[ $age -ge 17 && age -le 25 ]]
			then
				group="youth"
			else
				group="adult"
			fi

			echo "$name, your group is $group"
		fi
	fi
done
