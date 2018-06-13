/*
#include <stdio.h>
#include <utility>
using std::size_t;

template<typename T> //Реализации алгоритмов/Сортировка/Пузырьком @ https://ru.wikibooks.org/wiki/%D0%A0%D0%B5%D0%B0%D0%BB%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D0%B8_%D0%B0%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC%D0%BE%D0%B2/%D0%A1%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0/%D0%9F%D1%83%D0%B7%D1%8B%D1%80%D1%8C%D0%BA%D0%BE%D0%BC#C++_2
void bubble_sort(T array[], const size_t size) {
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = 0; j < size - i - 1; j++) {
			if (array[j + 1] < array[j])
				std::swap(array[j], array[j + 1]);
		}
	}
}

int main() {
	const size_t size{5};
	unsigned intArray[size] = {10, 15, 3, 99, 23};
	for(unsigned i{}; i < size; i++)
		printf("%u\n", intArray[i]);
	bubble_sort(intArray, size);
	puts("");
	for(unsigned i{}; i < size; i++)
		printf("%u\n", intArray[i]);
	return 0;
}
*/
