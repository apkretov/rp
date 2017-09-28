#include <string.h>

int stringStat(const char *string, size_t multiplier, int *count) {
	++*count;
	return ((int)strlen(string)) * multiplier;
}
