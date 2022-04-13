#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include <iostream>

class Bureaucrat;

class PresidentialPardonForm : public Form {
	public:
		PresidentialPardonForm(std::string target);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& form);
		using Form::operator=;
		void execute(Bureaucrat const &executor) const;
};

#endif
