//How do you compare structs for equality in C? @ https://stackoverflow.com/questions/141720/how-do-you-compare-structs-for-equality-in-c
#include <stdio.h>
#include <string.h>

struct testStruct {
	int i;
	char c;
};

/*
int compareStruct(const struct testStruct* sttTestStruct1, const struct testStruct* sttTestStruct2) { //How do you compare structs for equality in C? @ https://stackoverflow.com/questions/141720/how-do-you-compare-structs-for-equality-in-c
	return memcmp(sttTestStruct1, sttTestStruct2, sizeof(testStruct));
}*/

int main() {
	int intMemcmp{};
	testStruct sttTestStruct1, sttTestStruct2;

	memset(&sttTestStruct1, '0', sizeof(testStruct)); //memset @ http://www.cplusplus.com/reference/cstring/memset/
	memset(&sttTestStruct2, '0', sizeof(testStruct));

	sttTestStruct1.c = 'a';
	sttTestStruct1.i = 0;

	sttTestStruct2.c = 'a';
	sttTestStruct2.i = 0;

	intMemcmp = memcmp(&sttTestStruct1, &sttTestStruct2, sizeof(testStruct));
	printf("intMemcmp: %d\n", intMemcmp);
}
