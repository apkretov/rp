/*
#include <glob.h> // You can use the glob() function call for that. // How can I get only txt files from directory in c? @ https://stackoverflow.com/questions/12976733/how-can-i-get-only-txt-files-from-directory-in-c
#include <stdio.h>

int main(int argc, char **argv) {
	const char *pattern = "./*.cpp";
	glob_t pglob;

	glob(pattern, GLOB_ERR, NULL, &pglob);

	printf("Found %d matches\n", pglob.gl_pathc);
	printf("First match: %s\n", pglob.gl_pathv[0]);

	globfree(&pglob);

	return 0;
}
*/
