#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	#pragma omp parallel
	{
		cout << "Hello, World!" << endl;
	}
}
