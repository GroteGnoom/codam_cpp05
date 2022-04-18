#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include <iostream>

class Bureaucrat;

class Intern {
	public:
		Intern();
		virtual ~Intern();
		Intern(const Intern& intern);
		Intern &operator=(const Intern& intern);
		Form *makeForm(std::string name, std::string target) const;
};

#endif
