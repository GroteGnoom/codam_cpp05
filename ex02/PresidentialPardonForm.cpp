#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5, target)  {
	std::cout << "PresidentialPardonForm contructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& form) : Form(form.getName(), form.getSignGrade(), form.getExecGrade(), form.getTarget())  {
	std::cout << "PresidentialPardonForm copy contructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	check_execute(executor);
	std::cout << getTarget() << " has been pardoned by Zaphon Beeblebrox" << std::endl;
}
