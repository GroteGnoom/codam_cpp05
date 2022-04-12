#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

const char *Form::GradeTooLowException::what() const throw () {
	return "grade is too low!";
}

const char *Form::GradeTooHighException::what() const throw () {
	return "grade is too high!";
}

int Form::check_grade(int grade) {
	if (grade < 1)
		throw Form::GradeTooHighException();
	if (grade > 150)
		throw Form::GradeTooLowException();
	return grade;
}

void check_sign_grade(int sign_grade, int bureaucrat_grade) {
	if (bureaucrat_grade > sign_grade)
		throw Form::GradeTooLowException();
}

Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), _signed(false), _sign_grade(check_grade(sign_grade)), _exec_grade(check_grade(exec_grade)) {
	std::cout << "Form contructor called" << std::endl;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
};

Form::Form(const Form& form) : _name(form._name), _signed(form._signed), _sign_grade(form._sign_grade), _exec_grade(form._exec_grade) {
	std::cout << "Form copy contructor called" << std::endl;
}

Form &Form::operator=(const Form& form) {
	//assignment is mandatory, const attribute too :(
	//_name = form._name; 
	_signed = form._signed;
	return *this;
}

std::string Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

void Form::setSigned(bool s) {
	_signed = s;
}

int Form::getSignGrade() const {
	return _sign_grade;
}

int Form::getExecGrade() const {
	return _exec_grade;
}

void Form::beSigned(Bureaucrat b) {
	check_sign_grade(_sign_grade, b.getGrade());
	_signed = true;
}

std::ostream &Form::write(std::ostream &out) const {
	out << getName() << ", sign grade " << getSignGrade() << ", exec grade " << getExecGrade() << "," << (getSigned() ? "" : " not") << " signed";
	return out;
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
	return f.write(out);
}
