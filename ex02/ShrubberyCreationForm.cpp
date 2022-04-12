#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137, target)  {
	std::cout << "ShrubberyCreationForm contructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form) : Form(form.getName(), form.getSignGrade(), form.getExecGrade(), form._target)  {
	std::cout << "ShrubberyCreationForm copy contructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form) {
	setSigned(form.getSigned());
	setTarget(form.getTarget());
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	check_execute(executor);
	std::string filename = _target + "_shrubbery";
	std::ofstream out(filename);
	if (out.is_open()) {
		out << "       ~~~" << std::endl
			<< "   ~~~~   ~~~" << std::endl
			<< " ~~~ -  ~~-  ~~~~" << std::endl
			<< "~~ -  ~ ~~~  - ~~" << std::endl
			<< " ~~~~~- -  ~~_ ~~" << std::endl
			<< "   ~~~~~~~ ~~   " << std::endl
			<< "       | |     " << std::endl
			<< "       | |     " << std::endl
			<< "   ~~~~~ ~~~~"<< std::endl;
	}
	out.close();
}
