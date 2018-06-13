/*
#include <iostream>       // std::cout // future example @ http://www.cplusplus.com/reference/future/future/
#include <future>         // std::async, std::future
#include <chrono>         // std::chrono::milliseconds

bool is_prime(int x) { // a non-optimized way of checking for prime numbers:
	for (int i = 2; i < x; ++i)
		if (x % i == 0)
			return false;
	return true;
}

int main () {
	std::future<bool> fut = std::async(is_prime, 444444443); // call function asynchronously:

	std::cout << "checking, please wait"; // do something while waiting for function to set future:
	std::chrono::milliseconds span(100);
	while (fut.wait_for(span) == std::future_status::timeout)
		std::cout << '.' << std::flush;

	bool x = fut.get();     // retrieve return value
	std::cout << "\n444444443 " << (x ? "is" : "is not") << " prime.\n";
}
*/
