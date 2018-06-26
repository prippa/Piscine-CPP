#include "Form.hpp"

std::string	Form::getTarget(void) const { return (this->_target); }
void		Form::setTarget(std::string target) { this->_target = target; }

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Form: Exception with to High grade !");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Form: Exception with to Low grade !");
}

const char*	Form::NoSignedException::what() const throw()
{
	return ("Form: Exception with no signed form !");
}

void	Form::beSigned(Bureaucrat & obj)
{
	if (obj.getGrade() > this->_sign_grade)
		throw Form::GradeTooLowException();
	else if (this->_signed == 1)
		std::cout << obj.getName() << " cannot sign " << this->_name << " because the form is already signed." << std::endl;
	else
	{
		std::cout << obj.getName() << " signs " << this->_name << "." << std::endl;
		this->setSigned(true);
	}
}

void	Form::setSigned(bool sig) { this->_signed = sig; }
bool	Form::getSigned(void) const { return (this->_signed); }

std::string	Form::getName(void) const { return (this->_name); }
int			Form::getSignGrade(void) const { return (this->_sign_grade); }
int			Form::getExecGrade(void) const { return (this->_exec_grade); }

Form	&Form::operator = (Form const & obj)
{
	this->_signed = obj._signed;
	return (*this);
}

Form::Form(std::string name, int sign_grade, int exec_grade) :
	_name(name), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
	else if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	else
		this->_signed = false;
}

Form::Form(Form const & obj) :
	_name(obj._name), _sign_grade(obj._sign_grade), _exec_grade(obj._exec_grade)
{
	*this = obj;
}

Form::Form(void) : _name("Default"), _sign_grade(10), _exec_grade(125)
{
	this->_signed = false;
}

Form::~Form(void) {}

std::ostream	&operator<<(std::ostream & o, Form const & obj)
{
	o << obj.getName() << ", Form sign require : grade " << obj.getSignGrade() << ", exec require : " << obj.getExecGrade() << ", signed status : " << obj.getSigned();
	return o;
}
