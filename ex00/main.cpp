#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	Bureaucrat a("Ms. Bla", 1);
	Bureaucrat b("Ms. Bloe", 150);
	try {
		Bureaucrat c("Ms. Too low", 250);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat c("Ms. Too high", 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
}
