#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
	public:
		Form(std::string name, int sign_grade, int exec_grade);
		virtual ~Form();
		Form(const Form& form);
		Form &operator=(const Form& form);
		std::string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		class GradeTooLowException : public std::exception {
			const char *what() const throw ();
		};
		class GradeTooHighException : public std::exception {
			const char *what() const throw ();
		};
		void beSigned(Bureaucrat b);
	private:
		const std::string _name;
		bool _signed;
		const int _sign_grade;
		const int _exec_grade;
		int check_grade(int grade);
};

std::ostream &operator<<(std::ostream &out, const Form &b);
#endif
