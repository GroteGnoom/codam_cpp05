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

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form) : Form(form.getName(), form.getSignGrade(), form.getExecGrade(), form.getTarget())  {
	std::cout << "ShrubberyCreationForm copy contructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	check_execute(executor);
	std::string filename = getTarget() + "_shrubbery";
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
