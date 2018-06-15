/*
// auto keyword
// decltype specifier
// Lambda expressions
// Iterator-based functions from <functional>, <algorithm>, <numeric>, <iterator>.
//		<functional>:
//			placeholders
//			bind
//			function
//	First-class and higher-order functions offer map (std::map), filter (std::remove_if), and fold (std::accumulate).

#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <map>

namespace nsAutoDecltypeLambda { //auto keyword. decltype specifier. Lambda expressions.
	template <typename container, typename lambdaExpr>
	void for_each(container c, lambdaExpr le) { std::for_each(c.begin(), c.end(), le); }

	void printContainer() {
		unsigned i{};
		auto lambdaOut = [&i](int n) { std::cout << i++ << ": " << n << '\n'; };
		std::vector<unsigned> vec{52, 33, 81, 49, 10, 67};
		for_each(vec, lambdaOut);
	}

	void decltypeFn() {
		int i = 33;
		decltype(i) j = i * 2;
		std::cout << "i = " << i << ", " << "j = " << j << '\n';
		auto f = [](int a, int b)->int{ return a * b; };
		decltype(f) g = f; // the type of a lambda function is unique and unnamed
		i = f(2, 2);
		j = g(3, 3);
		std::cout << "i = " << i << ", " << "j = " << j << '\n';
	}
}

namespace nsFunctional { // Iterator-based functions from <functional>: placeholders, bind, function
	struct Foo {
		 Foo(int num) : num_(num) {}
		 int num_;
		 void printAdd(int i) { std::cout << num_ + i << '\n'; }
	} foo(10);

	std::function<void(int)> addDisplay = std::bind( &Foo::printAdd, foo, std::placeholders::_1 );  //Store a call to a member function and object.
}

namespace nsNumeric { // Iterator-based functions from <numeric>
	int myfunction (int x, int y) { return x + y; }

	void printAccumulate() {
		int init = 100;
		int array[] = {1, 2, 3};
		std::cout << std::accumulate(array, array + 3, init, myfunction) << '\n';
	}
}

namespace nsFirstHigher { //First-class and higher-order functions offer map (std::map), filter (std::remove_if), and fold (std::accumulate).
	void mapFn() {
		std::map<const char, std::function<float(float, float)>> arithm;
		arithm.insert(std::make_pair('+', [](float a, float b){ return a + b; }));
		arithm.insert(std::make_pair('-', [](float a, float b){ return a - b; }));
		std::cout << "2 + 3 = " << arithm['+'](2, 3) << '\n';
		std::cout << "2 - 3 = " << arithm['-'](2, 3) << '\n';
	}

	void fold() {
		const int init = 100;
		const int numbers[] = {10, 20, 30};
		std::cout << std::accumulate(numbers, numbers + 3, init, [](int x, int y) { return x + 2 * y; }) << '\n';
	}

	void filter() {
		///////////////
	}
}

int main() {
	nsAutoDecltypeLambda::printContainer(); //auto keyword. decltype specifier. Lambda expressions.
	nsAutoDecltypeLambda::decltypeFn();
	puts("");
	nsFunctional::addDisplay(10); // Iterator-based functions from <functional>: placeholders, bind, function
	puts("");
	nsNumeric::printAccumulate(); // Iterator-based functions from <numeric>
	puts("");
	nsFirstHigher::mapFn();
	nsFirstHigher::fold();
	///////////////nsFirstHigher::filter();
	return 0;
}
*/
