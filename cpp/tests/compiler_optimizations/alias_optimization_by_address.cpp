#include <cstdio>

int a[] = {1, 2, 3, 4, 5};
int b[] = {10, 20, 30, 40, 50};

void printArrays(){
	puts("a:");
	for (const auto& i : a)
		printf("%d ", i);
	printf("\nb:\n");
	for (const auto& j : b)
		printf("%d ", j);
	puts("");
}

int g(int x, int y) {
	return x + y;
};

void f1(int i, int j) {
	int *p, *q;
	int x, y;
	printArrays();
	p = &a[i];
	q = &b[j];
	x = *(q + 3);
	*p = 5;
	y = *(q + 3);
	g(x, y);
	printArrays();
}

void f2(int i, int j) {
	int *p, *q;
	int x, y;
	printArrays();
	p = &a[i];
	q = &b[j];
	x = *(q + 3);
	*p = 5;
	g(x, x);
	printArrays();
}

int main(){
	//f1(1, 2);
	f2(1, 2);
}
