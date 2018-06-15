/*
#include <iostream>

int main() {
	auto outerFunction = [](auto outerArg)	{
		return [=] (int innerArg)->auto{ return outerArg + innerArg; };
	};
	auto innerFunction = outerFunction(39);
	std::cout << innerFunction(12) << std::endl;
}
*/
