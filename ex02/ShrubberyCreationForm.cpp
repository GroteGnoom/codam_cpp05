#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target)  {
	std::cout << "ShrubberyCreationForm contructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form) : Form(form.getName(), form.getSignGrade(), form.getExecGrade()), _target(form._target)  {
	std::cout << "ShrubberyCreationForm copy contructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form) {
	//assignment is mandatory, const attribute too :(
	//_name = form._name; 
	setSigned(form.getSigned());
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const {
	return _target;
}

std::ostream &ShrubberyCreationForm::write(std::ostream &out) const {
	out << getName() << ", sign grade " << getSignGrade() << ", exec grade " << getExecGrade() << "," << (getSigned() ? "" : " not") << " signed, target " << getTarget();
	return out;
}
