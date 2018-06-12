/*
#include <algorithm> //map combinator @ http://blog.madhukaraphatak.com/functional-programming-in-c++/
#include <iostream>

template <typename Collection, typename unop>
Collection map(Collection col, unop op) {
	std::transform(col.begin(), col.end(), col.begin(), op);
	return col;
}

int main(int argc, char *argv[]) {
	auto lambda_echo = [](int i ) { std::cout << i << std::endl; };
	std::vector<int> col{20,24,37,42,23,45,37};
	auto addOne = [](int i) { return i+1; };
	auto returnCol = map(col, addOne);
	for_each(returnCol, lambda_echo);
	return 0;
}
*/
