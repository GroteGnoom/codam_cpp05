#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Form;

class Bureaucrat {
	public:
		Bureaucrat(std::string name, int grade);
		virtual ~Bureaucrat();
		Bureaucrat(const Bureaucrat& bureaucrat);
		Bureaucrat &operator=(const Bureaucrat& bureaucrat);
		int getGrade() const;
		std::string getName() const;
		void incGrade();
		void decGrade();
		class GradeTooLowException : public std::exception {
			const char *what() const throw ();
		};
		class GradeTooHighException : public std::exception {
			const char *what() const throw ();
		};
		void signForm(Form f);
	private:
		std::string const _name;
		int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
#endif
