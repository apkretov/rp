/*
#include <dirent.h>
#include <memory>
#include <cstring>

#define MAX_RECORDS_PER_TABLE 10
#define MAX_KEY_LEN 10

char **getKeys(char *data_dir, char* tablename, int *num_keys) { // @ http://qaru.site/questions/17239/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c
	//ORIG char** arr = malloc(MAX_RECORDS_PER_TABLE * sizeof(char*));
	char** arr = (char**)malloc(MAX_RECORDS_PER_TABLE * sizeof(char*));
	int i = 0;
	for (;i < MAX_RECORDS_PER_TABLE; i++)
		arr[i] = (char*)malloc( (MAX_KEY_LEN+1) * sizeof(char) );

	char *buf = (char *)malloc( (MAX_KEY_LEN+1)*sizeof(char) );
	snprintf(buf, MAX_KEY_LEN+1, "%s/%s", data_dir, tablename);

	DIR* tableDir = opendir(buf);
	struct dirent* getInfo;

	readdir(tableDir); // ignore '.'
	readdir(tableDir); // ignore '..'

	i = 0;
	while(1)	{
		getInfo = readdir(tableDir);
		if (getInfo == 0)
			break;
		strcpy(arr[i++], getInfo->d_name);
	}
	*(num_keys) = i;
	return arr;
}

int main() {
	char* data_dir{};
	char* tablename{};
	int* num_keys{};
	getKeys(data_dir, tablename, num_keys);
	//getKeys(data_dir, tablename, &num_keys);
}
*/
