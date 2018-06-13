/*
#include <functional> //std::placeholders @ http://www.cplusplus.com/reference/functional/placeholders/
#include <stdio.h>

int main() {
	using namespace std::placeholders;
	auto fn = [](const int x, const int y) { printf("%d + %d = %d\n", x, y, x + y); };
	auto bound_fn_100 = std::bind(fn, 100, _1);
	bound_fn_100(5);  // calls fn(100,5), i.e.: replacing _1 by the first argument: 5
	auto bound_fn_200 = std::bind(fn, 200, _1);
	bound_fn_200(10);
	return 0;
}
*/
