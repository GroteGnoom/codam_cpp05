#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
	public:
		Form(std::string name, int sign_grade, int exec_grade, std::string target);
		virtual ~Form();
		Form(const Form& form);
		Form &operator=(const Form& form);
		std::string getName() const;
		bool getSigned() const;
		void setSigned(bool s);
		int getSignGrade() const;
		int getExecGrade() const;
		std::string getTarget() const;
		void setTarget(std::string target);
		class GradeTooLowException : public std::exception {
			const char *what() const throw ();
		};
		class GradeTooHighException : public std::exception {
			const char *what() const throw ();
		};
		class NotSignedException : public std::exception {
			const char *what() const throw ();
		};
		void beSigned(Bureaucrat b);
		std::ostream &write(std::ostream &out) const;
		virtual void execute(Bureaucrat const &executor) const = 0;
		void check_execute(Bureaucrat const &b) const;
	private:
		const std::string _name;
		bool _signed;
		const int _sign_grade;
		const int _exec_grade;
		std::string _target;
		int check_grade(int grade);
};

std::ostream &operator<<(std::ostream &out, const Form &b);
#endif
