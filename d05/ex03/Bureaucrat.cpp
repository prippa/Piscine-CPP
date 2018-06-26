#include "Bureaucrat.hpp"

void	Bureaucrat::executeForm(Form const & form) const
{
	if (this->getGrade() < form.getExecGrade())
	{
		std::cout << this->_name << " executes " << form.getTarget() << "." << std::endl;
		form.execute(*this);
	}
	else
		std::cout << "Cannot execute form because the bureaucrat's grade is too low." << std::endl;
}

void	Bureaucrat::signForm(Form & f)
{
	if (this->_grade <= f.getSignGrade() && f.getSigned() == false) {
		std::cout << this->_name << " signs " << f.getName() << std::endl;
		f.setSigned(true);
	}
	else if (this->_grade > f.getSignGrade()) {
		std::cout << this->_name << " cannot sign " << f.getName() << " because his grade is too low." << std::endl;
	}
	else if (f.getSigned() == true) {
		std::cout << this->_name << " cannot sign " << f.getName() << " because the form is already signed." << std::endl;
	}
}

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

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: Exception with to High grade !");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: Exception with to Low grade !");
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
