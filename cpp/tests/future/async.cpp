/*
#include <iostream>       // std::cout // async example @ http://www.cplusplus.com/reference/future/async/
#include <future>         // std::async, std::future

bool is_prime(int x) { // a non-optimized way of checking for prime numbers:
  std::cout << "Calculating. Please, wait...\n";
  for (int i = 2; i < x; ++i)
	  if (x%i == 0)
		  return false;
  return true;
}

int main () {
  std::future<bool> fut = std::async(is_prime, 313222313); // call is_prime(313222313) asynchronously:

  std::cout << "Checking whether 313222313 is prime.\n";
  // ...

  bool ret = fut.get();      // waits for is_prime to return

  if (ret)
	  std::cout << "It is prime!\n";
  else
	  std::cout << "It is not prime.\n";

  return 0;
}
*/
