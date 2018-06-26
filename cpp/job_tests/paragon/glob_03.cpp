/*
#include <glob.h> // Alternatively, instead of using opendir, readdir, and closedir, you can use the glob(3) function: // How can I get only txt files from directory in c? @ https://stackoverflow.com/questions/12976733/how-can-i-get-only-txt-files-from-directory-in-c
#include <cstdlib>

int main() {
	glob_t globbuf;
	if(glob("/path/to/dir/*.txt", 0, NULL, &globbuf) == 0)
	{
		int i;
		for(i = 0; i < globbuf.gl_pathc; i++)
			process_filename(globbuf.gl_pathv[i]);
	}
	globfree(&globbuf);
}
*/
