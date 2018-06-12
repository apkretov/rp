/*
auto keyword
Lambda expressions
*/

/*
#include <iostream>
#include <algorithm>

template <typename container, typename lambdaExpr>
void for_each(container c, lambdaExpr le) {
	std::for_each(c.begin(), c.end(), le);
}

int main() {
	unsigned i{};
	auto lambdaOut = [&i](int n) { std::cout << i++ << ": " << n << std::endl; };
	std::vector<unsigned> vec{52, 33, 81, 49, 10, 67};
	for_each(vec, lambdaOut);
}
*/
