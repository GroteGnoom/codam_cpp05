#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <iostream>

class Bureaucrat;

class ShrubberyCreationForm : public Form {
	public:
		ShrubberyCreationForm(std::string target);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& form);
		using Form::operator=;
		std::ostream &write(std::ostream &out) const;
		void execute(Bureaucrat const &executor) const;
};

#endif
