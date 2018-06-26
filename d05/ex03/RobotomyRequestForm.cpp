#include "RobotomyRequestForm.hpp"

RobotomyRequestForm	&RobotomyRequestForm::operator = (RobotomyRequestForm const & obj)
{
	this->setSigned(obj.getSigned());
	this->setTarget(obj.getTarget());
	return (*this);
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & obj) : Form("Default", 72, 45)
{
	*this = obj;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Default", 72, 45) { this->setTarget(target); }
RobotomyRequestForm::RobotomyRequestForm(void) : Form("Default", 72, 45) {}
RobotomyRequestForm::~RobotomyRequestForm(void) {}


void	RobotomyRequestForm::execute(Bureaucrat const & obj) const
{
	if (this->getSigned() == false)
		throw Form::NoSignedException();
	else if (obj.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
	else
	{
		std::cout << "ZZZZZZZZZHHHHH" << std::endl;
		if (rand() % 2)
			std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
		else
			std::cout << "It's a failure." << std::endl;
	}
}
