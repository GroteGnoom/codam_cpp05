#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <map>

Intern::Intern() {
	std::cout << "Intern contructor called" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
};

Intern::Intern(const Intern& intern) {
	(void)intern;
	std::cout << "Intern copy contructor called" << std::endl;
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
	std::map<std::string, Form *(*)(std::string)> consmap;
	consmap["robotomy request"] = robotomy_request;
	consmap["presidential pardon"] = presidential_pardon;
	consmap["shrubbery creation"] = shrubbery_creation;
	Form *form = consmap[name](target);
	std::cout << "Intern creates " << *form << std::endl;
	return form;
}
