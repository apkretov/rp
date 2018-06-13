/*
#include <iostream>       // std::cout // future::future @ http://www.cplusplus.com/reference/future/future/future/
#include <future>         // std::async, std::future

int get_value() {
	return 10;
}

int main () {
  std::future<int> foo;                            // default-constructed
  std::future<int> bar = std::async(get_value);   // move-constructed

  int x = bar.get();
  std::cout << "value: " << x << '\n';
}
*/
