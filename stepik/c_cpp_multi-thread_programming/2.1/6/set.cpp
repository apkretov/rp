#include <iostream>
using namespace std;
#include <set>

struct comparator {
	bool operator()(const int& a, const int& b) const { return a > b; }
};

int main(int agrc, char** argv) {
	set<int, comparator> s;

	s.insert(5);
	s.insert(3);
	s.insert(4);
	s.insert(1);
	s.insert(2);

	//ORIG for (auto i = s.begin(); i != s.end(); i++)
	for (set<int>::iterator i = s.cbegin(); i != s.cend(); i++) //TEST
		cout << *i << ' ';
	cout << endl;
}
