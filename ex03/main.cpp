#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
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
	RobotomyRequestForm fc("notSignedTargetwoohoo");
	a.executeForm(fc);

	std::cout << "-------------RobotomyRequestForms!----------" << std::endl;
	RobotomyRequestForm ra("robotomytarget");
	RobotomyRequestForm rb("R2");
	std::cout << "form a is " << ra << std::endl;
	std::cout << "form b is " << rb << std::endl;

	std::cout << "-------------Signing forms!----------" << std::endl;
	a.signForm(ra);
	a.signForm(rb);
	b.signForm(ra);
	b.signForm(rb);

	std::cout << "-------------executing forms----------" << std::endl;
	a.executeForm(ra);
	b.executeForm(ra);
	RobotomyRequestForm rc("notSignedTargetwoohoo");
	a.executeForm(rc);

	std::cout << "-------------PresidentialPardonForms!----------" << std::endl;
	PresidentialPardonForm pa("pardontarget");
	PresidentialPardonForm pb("R2");
	std::cout << "form a is " << pa << std::endl;
	std::cout << "form b is " << pb << std::endl;

	std::cout << "-------------Signing forms!----------" << std::endl;
	a.signForm(pa);
	a.signForm(pb);
	b.signForm(pa);
	b.signForm(pb);

	std::cout << "-------------executing forms----------" << std::endl;
	a.executeForm(pa);
	b.executeForm(pa);
	PresidentialPardonForm pc("notSignedTargetwoohoo");
	a.executeForm(pc);

	std::cout << "-------------intern!----------" << std::endl;

    Intern  someRandomIntern;
    Form*   rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;

	std::cout << "-------------the great destruction ---------" << std::endl;
}