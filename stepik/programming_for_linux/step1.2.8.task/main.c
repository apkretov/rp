#include <stdio.h>
#include "solution.c"

int main() {
	char* chrString = "test";
	int intCount = 1;
	printf("stringStat = %i\n", stringStat(chrString, 2, &intCount));
	printf("intCout = %i\n", intCount);
	return 0;
}
