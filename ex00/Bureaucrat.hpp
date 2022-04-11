#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	public:
		Bureaucrat(std::string name, int grade);
		virtual ~Bureaucrat();
		Bureaucrat(const Bureaucrat& bureaucrat);
		Bureaucrat &operator=(const Bureaucrat& bureaucrat);
		int getGrade();
		std::string getName();
		void incGrade();
		void decGrade();
		class GradeTooLowException : public std::exception {
			const char *what() const throw ();
		};
		class GradeTooHighException : public std::exception {
			const char *what() const throw ();
		};
	private:
		std::string const _name;
		int _grade;
};

#endif
