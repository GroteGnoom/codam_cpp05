#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	std::cout << "-------------Bureaucrats!----------\n";
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

	std::cout << "-------------Forms!----------\n";
	Form fa("form A", 1, 3);
	Form fb("form B", 150, 3);
	try {
		Form fc("form too low", 250, 3);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form fc("form too high", 0, 3);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "form a is " << fa << std::endl;
	std::cout << "form b is " << fb << std::endl;

	std::cout << "-------------Signing forms!----------\n";
	a.signForm(fa);
	a.signForm(fb);
	b.signForm(fa);
	b.signForm(fb);
}
