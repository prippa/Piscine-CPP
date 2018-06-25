#include "Bureaucrat.hpp"

void	Bureaucrat::upGrade(void)
{
	if ((this->_grade - 1) < 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade--;
}

void	Bureaucrat::downGrade(void)
{
	if ((this->_grade + 1) > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade++;
}

std::string	Bureaucrat::getName(void) const { return (this->_name); }

int			Bureaucrat::getGrade(void) const { return (this->_grade); }

Bureaucrat	&Bureaucrat::operator = (Bureaucrat const & obj)
{
	this->_grade = obj.getGrade();
	return (*this);
}
Bureaucrat::Bureaucrat(Bureaucrat const & obj) : _name(obj.getName()), _grade(obj.getGrade()) {}
Bureaucrat::Bureaucrat(std::string const name, int const grade) : _name(name)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = grade;
}
Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(1) {}
Bureaucrat::~Bureaucrat(void) {}

std::ostream	&operator << (std::ostream &o, Bureaucrat const & obj)
{
	o << obj.getName() << ", Bureaucrat grade " << obj.getGrade();
	return o;
}
