#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
	std::cout << "-------------Bureaucrats!----------" << std::endl;
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

	std::cout << "-------------ShrubberyCreationForms!----------" << std::endl;
	ShrubberyCreationForm fa("shrubberytarget");
	ShrubberyCreationForm fb("T2");
	std::cout << "form a is " << fa << std::endl;
	std::cout << "form b is " << fb << std::endl;

	std::cout << "-------------Signing forms!----------" << std::endl;
	a.signForm(fa);
	a.signForm(fb);
	b.signForm(fa);
	b.signForm(fb);

	std::cout << "-------------executing forms----------" << std::endl;
	a.executeForm(fa);
	b.executeForm(fa);
	ShrubberyCreationForm fc("notSignedTargetwoohoo");
	a.executeForm(fc);

	std::cout << "-------------the great destruction ---------" << std::endl;
}
