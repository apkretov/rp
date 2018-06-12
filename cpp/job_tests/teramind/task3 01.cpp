//Recursive Function to Calculate Nth Term of Fibonacci Series @ http://dewsacademy.com/programming%20codes/CProgrammingCodes.html#rfcntfs
#include<stdio.h>
//#include<conio.h>

int fibo(int n) {
	if (n==1)
		return 0;
	if (n==2)
		return 1;
	return fibo(n-1) + fibo(n-2);
}

int main() { //Write a recursive function to calculate nth term of Fibonacci series
	int n;
	printf("Enter n : ");
	scanf("%d", &n);
	printf("The %dth term of Fibonacci sequence is %d\n", n, fibo(n));
	return 0;
}
