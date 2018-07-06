#include<iostream> // What is the difference between new/delete and malloc/free? @ https://stackoverflow.com/questions/240212/what-is-the-difference-between-new-delete-and-malloc-free
using namespace std;

class ABC{
public: ABC(){
		cout << "Hello" << endl;
	}
	void disp(){
		cout << "Hi\n";
	}

};

int main() { cout << "111\n";
	ABC* b = (ABC*)malloc(sizeof(ABC)); cout << "222\n";
	int* q = new int[20]; cout << "333\n";
	ABC *a = new ABC(); cout << "444\n";
	b->disp(); cout << "555\n";

	cout << a << endl; //TEST
	cout << b << endl; cout << "666\n";
	free(b); cout << "777\n";
	delete b; cout << "888\n";
	//a=NULL;
	b->disp(); cout << "999\n";
	ABC(); cout << "100\n";
	cout << b;  cout << "110\n";
	return 0;
}
