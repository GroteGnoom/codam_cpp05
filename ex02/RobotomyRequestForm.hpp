#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <iostream>

class Bureaucrat;

class RobotomyRequestForm : public Form {
	public:
		RobotomyRequestForm(std::string target);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& form);
		using Form::operator=;
		void execute(Bureaucrat const &executor) const;
};

#endif
