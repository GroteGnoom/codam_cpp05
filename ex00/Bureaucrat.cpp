#include "Bureaucrat.hpp"
#include <iostream>

const char *Bureaucrat::GradeTooLowException::what() const throw () {
	return "too low!";
}

const char *Bureaucrat::GradeTooHighException::what() const throw () {
	return "too high!";
}

void check_grade(int grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	check_grade(grade);
	_grade = grade;
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
	//assignment is mandatory, const attribute too :(
	//_name = bureaucrat._name; 
	_grade = bureaucrat._grade;
	return *this;
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::decGrade() {
	check_grade(_grade + 1);
	_grade++;
}

void Bureaucrat::incGrade() {
	check_grade(_grade - 1);
	_grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}
