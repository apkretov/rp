/*
#include <functional> //std::function @ http://en.cppreference.com/w/cpp/utility/functional/function
#include <iostream>

struct Foo {
	 Foo(int num) : num_(num) {}
	 int num_;
	 void print_add(int i) const {
		 std::cout << num_ + i << '\n';
	 }
};

void print_num(int i) {
	 std::cout << i << '\n';
}

struct PrintNum {
	 void operator()(int i) const {
		  std::cout << i << '\n';
	 }
};

int main() {
	 std::function<void(int)> f_display = print_num; // store a free function
	 f_display(-9);

	 std::function<void()> f_display_42 = []() { print_num(42); }; // store a lambda
	 f_display_42();

	 std::function<void()> f_display_31337 = std::bind(print_num, 31337); // store the result of a call to std::bind
	 f_display_31337();

	 std::function<void(const Foo&, int)> f_add_display = &Foo::print_add; // store a call to a member function
	 const Foo foo(314159);
	 f_add_display(foo, 1);
	 f_add_display(314159, 1);

	 std::function<int(Foo const&)> f_num = &Foo::num_; // store a call to a data member accessor
	 std::cout << "num_: " << f_num(foo) << '\n';

	 using std::placeholders::_1; // store a call to a member function and object
	 std::function<void(int)> f_add_display2 = std::bind( &Foo::print_add, foo, _1 );
	 f_add_display2(2);

	 std::function<void(int)> f_add_display3 = std::bind( &Foo::print_add, &foo, _1 ); // store a call to a member function and object ptr
	 f_add_display3(3);

	 std::function<void(int)> f_display_obj = PrintNum(); // store a call to a function object
	 f_display_obj(18);
}
*/
