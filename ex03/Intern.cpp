#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {
	std::cout << "Intern contructor called\n";
}

Intern::~Intern() {
	std::cout << "Intern destructor called\n";
};

Intern::Intern(const Intern& intern) {
	(void)intern;
	std::cout << "Intern copy contructor called\n";
}

Intern &Intern::operator=(const Intern& intern) {
	(void)intern;
	return (*this);
}

static Form *robotomy_request(std::string target) {
	return new RobotomyRequestForm(target);
}

static Form *presidential_pardon(std::string target) {
	return new PresidentialPardonForm(target);
}

static Form *shrubbery_creation(std::string target) {
	return new ShrubberyCreationForm(target);
}

Form *Intern::makeForm(std::string name, std::string target) const {
	std::string formnames[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	Form *(*forms[])(std::string) = {robotomy_request,  presidential_pardon, shrubbery_creation};
	for (int i = 0; i < 3; i++) {
		if (name == formnames[i]) {
			Form *form = forms[i](target);
			std::cout << "Intern creates " << *form << "\n";
			return form;
		}
	}
	std::cout << "Intern could not handle " << name << "\n";
	return NULL;
}
