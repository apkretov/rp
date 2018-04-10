gcd ()
{
dividend=$1 
divisor=$2 

remainder=1 

if [ $divisor -eq 0 ]
then
echo "GCD of $dividend and $divisor = $dividend"
exit 0
fi

until [ "$remainder" -eq 0 ]
do
let "remainder = $dividend % $divisor"

dividend=$divisor 
divisor=$remainder
done 
} 

while [ 1 ]
do
	read number1 number2
	if [[ -z $number1 ]]
	then
		echo "bye"
		break
	fi
	gcd $number1 $number2
	echo "GCD is $dividend"
done

exit 0
