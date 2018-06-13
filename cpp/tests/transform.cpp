/*
#include <iostream>     // std::cout // transform algorithm example @ http://www.cplusplus.com/reference/algorithm/transform/
#include <algorithm>    // std::transform
#include <vector>       // std::vector
#include <functional>   // std::plus

int op_increase (int i) { return ++i; }

int main () {
	std::vector<int> foo, bar;
	for (int i = 1; i < 6; i++) // set some values:
		foo.push_back (i * 10); // foo: 10 20 30 40 50
	bar.resize(foo.size()); // allocate space
	std::transform(foo.cbegin(), foo.cend(), bar.begin(), op_increase); // bar: 11 21 31 41 51
	std::transform(foo.cbegin(), foo.cend(), bar.cbegin(), foo.begin(), std::plus<int>()); // std::plus adds together its two arguments: // foo: 21 41 61 81 101
	std::cout << "foo contains:";
	//ORIG for (std::vector<int>::iterator it=foo.begin(); it!=foo.end(); ++it)
	for (auto it = foo.cbegin(); it != foo.cend(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	return 0;
}
*/
