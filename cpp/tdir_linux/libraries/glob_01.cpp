/*
#include <glob.h>
#include <stdlib.h> //NULL //EXIT_SUCCESS, EXIT_FAILURE @ https://en.cppreference.com/w/c/program/EXIT_status
#include <iostream>
using std::cout;
using std::endl;

int main() {
	glob_t glob_result; //Почему бы не использовать glob()? @ http://qaru.site/questions/17239/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c
	glob("/home/alex/Downloads/",GLOB_TILDE,NULL,&glob_result);
	for(unsigned int i=0; i<glob_result.gl_pathc; ++i){
		cout << glob_result.gl_pathv[i] << endl;
	}
}
*/
