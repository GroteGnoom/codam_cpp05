#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137, target)  {
	std::cout << "ShrubberyCreationForm contructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called\n";
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form) : Form(form.getName(), form.getSignGrade(), form.getExecGrade(), form.getTarget())  {
	std::cout << "ShrubberyCreationForm copy contructor called\n";
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	check_execute(executor);
	std::string filename = getTarget() + "_shrubbery";
	std::ofstream out(filename);
	if (out.is_open()) {
		out << "       ~~~\n"
			<< "   ~~~~   ~~~\n"
			<< " ~~~ -  ~~-  ~~~~\n"
			<< "~~ -  ~ ~~~  - ~~\n"
			<< " ~~~~~- -  ~~_ ~~\n"
			<< "   ~~~~~~~ ~~\n"
			<< "       | |\n"
			<< "       | |\n"
			<< "   ~~~~~ ~~~~"<< "\n";
	}
	out.close();
}
