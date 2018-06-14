// auto keyword
// decltype specifier
// Lambda expressions
// Iterator-based functions from the libraries: <functional>, <algorithm>, <numeric>, <iterator>:
//		<functional>:
//			placeholders
//			bind
//			function
//		<algorithm>:
//			for_each (before C++11)
//			transform (before C++11)
//		<numeric>:
//			accumulate (before C++11)

#include <iostream>
#include <algorithm>
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

#include <functional>
namespace nsFunctional { // Iterator-based functions from <functional>: placeholders, bind, function
	struct Foo {
		 Foo(int num) : num_(num) {}
		 int num_;
		 void printAdd(int i) { std::cout << num_ + i << '\n'; }
	} foo(10);

	std::function<void(int)> addDisplay = std::bind( &Foo::printAdd, foo, std::placeholders::_1 );  //Store a call to a member function and object.
}

#include <numeric>
namespace nsNumeric { // Iterator-based functions from <numeric>
	int myfunction (int x, int y) { return x + y; }

	void printAccumulate() {
		int init = 100;
		int array[] = {1, 2, 3};
		std::cout << std::accumulate(array, array + 3, init, myfunction) << '\n';
	}
}

int main() {
	nsAutoDecltypeLambda::printContainer(); //auto keyword. decltype specifier. Lambda expressions.
	nsAutoDecltypeLambda::decltypeFn();
	std::cout << '\n';
	nsFunctional::addDisplay(10); // Iterator-based functions from <functional>: placeholders, bind, function
	std::cout << '\n';
	nsNumeric::printAccumulate(); // Iterator-based functions from <numeric>
	return 0;
}
