#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	std::cout << "-------------Bureaucrats!----------\n";
	Bureaucrat a("Ms. Bla", 1);
	Bureaucrat b("Ms. Bloe", 150);
	try {
		Bureaucrat c("Ms. Too low", 250);
	}
	catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
	try {
		Bureaucrat c("Ms. Too high", 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
	std::cout << "a is " << a << "\n";
	std::cout << "b is " << b << "\n";

	std::cout << "-------------ShrubberyCreationForms!----------\n";
	ShrubberyCreationForm fa("shrubberytarget");
	ShrubberyCreationForm fb("T2");
	std::cout << "form a is " << fa << "\n";
	std::cout << "form b is " << fb << "\n";

	std::cout << "-------------Signing forms!----------\n";
	a.signForm(fa);
	a.signForm(fb);
	b.signForm(fa);
	b.signForm(fb);

	std::cout << "-------------executing forms----------\n";
	a.executeForm(fa);
	b.executeForm(fa);
	RobotomyRequestForm fc("notSignedTargetwoohoo");
	a.executeForm(fc);

	std::cout << "-------------RobotomyRequestForms!----------\n";
	RobotomyRequestForm ra("robotomytarget");
	RobotomyRequestForm rb("R2");
	std::cout << "form a is " << ra << "\n";
	std::cout << "form b is " << rb << "\n";

	std::cout << "-------------Signing forms!----------\n";
	a.signForm(ra);
	a.signForm(rb);
	b.signForm(ra);
	b.signForm(rb);

	std::cout << "-------------executing forms----------\n";
	a.executeForm(ra);
	b.executeForm(ra);
	RobotomyRequestForm rc("notSignedTargetwoohoo");
	a.executeForm(rc);

	std::cout << "-------------PresidentialPardonForms!----------\n";
	PresidentialPardonForm pa("pardontarget");
	PresidentialPardonForm pb("R2");
	std::cout << "form a is " << pa << "\n";
	std::cout << "form b is " << pb << "\n";

	std::cout << "-------------Signing forms!----------\n";
	a.signForm(pa);
	a.signForm(pb);
	b.signForm(pa);
	b.signForm(pb);

	std::cout << "-------------executing forms----------\n";
	a.executeForm(pa);
	b.executeForm(pa);
	PresidentialPardonForm pc("notSignedTargetwoohoo");
	a.executeForm(pc);

	std::cout << "-------------intern!----------\n";

    Intern  someRandomIntern;
    Form*   rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;
    rrf = someRandomIntern.makeForm("presidential pardon", "Bloebla");
	delete rrf;
    rrf = someRandomIntern.makeForm("nonexistent", "Bloeblablie");
	delete rrf;

	std::cout << "-------------the great destruction ---------\n";
}
