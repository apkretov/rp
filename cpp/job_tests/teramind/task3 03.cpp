#include<stdio.h>
//#include <exception>

static unsigned fibonacci(unsigned n) {
	unsigned fiboNum{};
	if (n == 1)
		fiboNum = 0;
	else if (n == 2)
		fiboNum = 1;
	else
		fiboNum = fibonacci(n-1) + fibonacci(n-2);
	return fiboNum;
}

int main() {
	unsigned n{};
	unsigned fiboNum{};

	printf("Enter a ordinal interger number (> 0) of a term in the Fibonacci sequence: ");
	scanf("%u", &n);
	if (n > 0) {
		fiboNum = fibonacci(n);
		printf("The %dth term in the Fibonacci sequence: %u.\n", n, fiboNum);
	}	else
		printf("An ordinal number of a term must be interger and > 0!\n");
	return 0;
}
