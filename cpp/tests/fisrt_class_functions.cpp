/*
#include <iostream> //First-class functions: dispatch table, page 8 @ https://www.grimm-jaud.de/images/stories/pdfs/FunctionalProgrammingInC++11.pdf
#include <functional>
#include <map>
#include <math.h>

namespace nsFirstHigher { // First-class and higher-order functions
	void fisrt_class() {
		std::map<const char, std::function<float(float, float)>> arithm;
		arithm.insert(std::make_pair('+', [](float a, float b){ return a + b; }));
		arithm.insert(std::make_pair('-', [](float a, float b){ return a - b; }));
		arithm.insert(std::make_pair('*', [](float a, float b){ return a * b; }));
		arithm.insert(std::make_pair('/', [](float a, float b){ return a / b; }));
		arithm.insert(std::make_pair('^', [](float a, float b){ return pow(a, b); }));
		std::cout << "2 + 3 = " << arithm['+'](2, 3) << '\n';
		std::cout << "2 * 3 = " << arithm['*'](2, 3) << '\n';
		std::cout << "2 ^ 3 = " << arithm['^'](2, 3) << '\n';
	}
}

int main() {
	nsFirstHigher::fisrt_class();
	return 0;
}
*/
