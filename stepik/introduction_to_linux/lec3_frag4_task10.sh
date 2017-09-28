#! /bin/bash

while [ 1 ]
do
	read var1 var2 var3

	if [[ $var1 == "exit" ]]; then
		echo "bye"
		break
	elif [[ -z $var1 || -z $var2 || -z $var3 ]]; then
		echo "error"
		break
	elif [[ $var2 != "+" && $var2 != "-" && $var2 != "*" && $var2 != "/" && $var2 != "%" && $var2 != "**" ]]; then
		echo "error"
		break
	else
		case $var2 in
		"+")
			let result=$var1+$var3
			;;
		"-")
			let result=$var1-$var3
			;;
		"*")
			let result=$var1*$var3
			;;
		"/")
			let result=$var1/$var3
			;;
		"%")
			let result=$var1%$var3
			;;
		"**")
			let result=$var1**$var3
			;;
		esac
		echo $result
	fi
done
