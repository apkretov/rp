#include <stdlib.h>
#include <dmalloc.h>
#include <stdio.h>

void leak(int n) {
	malloc(n);
}

int main(int argc, char** agrv) {
	leak(1);
	leak(2);
	leak(3);

 	void* m = malloc(1024);
	free(m);
	
	printf("Leakage tested!\n");

	return 0;
}
