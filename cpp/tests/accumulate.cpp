/*
// accumulate example @ http://www.cplusplus.com/reference/numeric/accumulate/
#include <iostream>     // std::cout
#include <functional>   // std::minus
#include <numeric>      // std::accumulate

int myfunction (const int x, const int y) { return x + 2 * y; }

struct myclass {
	int operator()(const int x, const int y) { return x + 3 * y; }
} myobject;

int main () {
  const int init = 100;
  const int numbers[] = {10, 20, 30};

  std::cout << "using default accumulate: ";
  std::cout << std::accumulate(numbers, numbers + 3, init);
  std::cout << '\n';

  std::cout << "using functional's minus: ";
  std::cout << std::accumulate(numbers, numbers + 3, init, std::minus<int>());
  std::cout << '\n';

  std::cout << "using custom function: ";
  std::cout << std::accumulate(numbers, numbers + 3, init, myfunction);
  std::cout << '\n';

  std::cout << "using lambda expression: ";
  //std::cout << std::accumulate(numbers, numbers + 3, init, [](const int x, const int y) { return x + 2 * y; });
  std::cout << std::accumulate(numbers, numbers + 3, init, [](int x, int y) { return x + 2 * y; });
  std::cout << '\n';

  std::cout << "using custom object: ";
  std::cout << std::accumulate(numbers, numbers + 3, init, myobject);
  std::cout << '\n';

  return 0;
}
*/
