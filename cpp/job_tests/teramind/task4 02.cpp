// auto keyword
// Lambda expressions
// decltype specifier
// Iterator-based functions from the libraries: <functional>, <algorithm>, <numeric>, <iterator>:
//		<functional>:
//			placeholders
//			bind
//			function
//		<algorithm>:
//			transform (before C++11)

#include <iostream>
#include <algorithm>

namespace auto_lambda { //auto keyword. Lambda expressions.
	template <typename container, typename lambdaExpr>
	void for_each(container c, lambdaExpr le) { std::for_each(c.begin(), c.end(), le); }

	void fn() {
		unsigned i{};
		auto lambdaOut = [&i](int n) { std::cout << i++ << ": " << n << std::endl; };
		std::vector<unsigned> vec{52, 33, 81, 49, 10, 67};
		for_each(vec, lambdaOut);
	}
}

#include <functional> // Iterator-based functions from <functional>: placeholders, bind, function
namespace functional {
	float divide(float x, float y) { return x / y; }

	struct pair {
	  float a, b;
	  float multiply() { return a * b; }
	};

	void placeholders_bind() {
	  using namespace std::placeholders;
	  auto round = std::bind<int>(divide, _1, _2);
	  std::cout << round(5, 2) << '\n';

	  pair pr{5, 4};
	  auto boundFn = std::bind(&pair::multiply, _1);
	  std::cout << boundFn(pr) << '\n';
	}
}

int main() {
	auto_lambda::fn(); //auto keyword. Lambda expressions.
	std::cout << std::endl;
	functional::placeholders_bind(); // Iterator-based functions from <functional>: placeholders, bind, function
	return 0;
}
