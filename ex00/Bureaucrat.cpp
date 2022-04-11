#include "Bureaucrat.hpp"
#include <iostream>

const char *Bureaucrat::GradeTooLowException::what() const throw () {
	return "too low!";
}

const char *Bureaucrat::GradeTooHighException::what() const throw () {
	return "too high!";
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Bureaucrat contructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) {
	std::cout << "Bureaucrat copy contructor called" << std::endl;
	*this = bureaucrat;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& bureaucrat) {
	_name = bureaucrat._name;
	_grade = bureaucrat._grade;
	return *this;
}

std::string Bureaucrat::getName() {
	return _name;
}

int Bureaucrat::getGrade() {
	return _grade;
}

void Bureaucrat::incGrade() {
	if (_grade > 149)
		throw Bureaucrat::GradeTooHighException();
	_grade++;
}

void Bureaucrat::decGrade() {
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade++;
}

