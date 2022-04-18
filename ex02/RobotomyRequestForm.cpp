#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45, target)  {
	std::cout << "RobotomyRequestForm contructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called\n";
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form) : Form(form.getName(), form.getSignGrade(), form.getExecGrade(), form.getTarget())  {
	std::cout << "RobotomyRequestForm copy contructor called\n";
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	check_execute(executor);
	std::cout << "BZZZZZZZZZZ\n";
    std::srand(std::time(NULL));
	if (std::rand() % 2) {
		std::cout << getTarget() << " has been robotomized succesfully\n";
	} else {
		std::cout << getTarget() << " has not been robotomized\n";
	}
}
