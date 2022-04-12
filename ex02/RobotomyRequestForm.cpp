#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45, target)  {
	std::cout << "RobotomyRequestForm contructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form) : Form(form.getName(), form.getSignGrade(), form.getExecGrade(), form.getTarget())  {
	std::cout << "RobotomyRequestForm copy contructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	check_execute(executor);
	std::cout << "BZZZZZZZZZZ" << std::endl;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
	if (std::rand() % 2) {
		std::cout << getTarget() << " has been robotomized succesfully" << std::endl;
	} else {
		std::cout << getTarget() << " has not been robotomized" << std::endl;
	}
}
