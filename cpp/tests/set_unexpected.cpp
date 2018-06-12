/*
#include <iostream>       // std::cerr						// set_unexpected example @ http://www.cplusplus.com/reference/exception/set_unexpected/
#include <exception>      // std::set_unexpected

void myunexpected () {
	std::cerr << "unexpected called\n";
	throw 0;     // throws int (in exception-specification)
}

void myfunction () throw (int) {
	throw 'x';   // throws char (not in exception-specification)
}

int main (void) {
	std::set_unexpected (myunexpected);
	try {
		myfunction();
	}
	catch (int) { std::cerr << "caught int\n"; }
	catch (...) { std::cerr << "caught some other exception type\n"; }
	return 0;
}
*/
