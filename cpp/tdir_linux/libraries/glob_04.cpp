/*
#include <glob.h> // Very briefly (and wholly untested) you might try something like this // How can I get only txt files from directory in c? @ https://stackoverflow.com/questions/12976733/how-can-i-get-only-txt-files-from-directory-in-c
#include <stdio.h>

void glob_example() {
	glob_t g;
	int i;
	glob("*.cpp", 0, NULL, &g);
	for (i = 0; i < g.gl_pathc; i++)
		printf("matched: %s\n", g.gl_pathv[i]);
	globfree(&g);
}

int main () {
	glob_example();
}
*/
