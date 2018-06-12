/*
#include <stdio.h>
#include <string.h>

int main() {
	struct s {
		int i;
		char c;
	} s1, s2;

	memset(&s1, '0', sizeof(s));
	memset(&s2, '0', sizeof(s));

	s1.c = 'a';
	s1.i = 100;

	s2.c = 'a';
	s2.i = 100;

	if (memcmp(&s1, &s2, sizeof(s)) == 0)
		printf("Members have the same value.\n");
	else
		printf("Members have different value.\n");
}
*/
