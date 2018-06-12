//std::perror @ http://en.cppreference.com/w/cpp/io/c/perror
#include <cmath>
#include <cerrno>
#include <cstdio>

int main() {
	 double not_a_number = std::log(-1.0);
	 if (errno == EDOM) {
		  std::perror("log(-1) failed");
	 }
}
