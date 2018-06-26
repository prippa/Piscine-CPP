#include "PresidentialPardonForm.hpp"

PresidentialPardonForm	&PresidentialPardonForm::operator = (PresidentialPardonForm const & obj)
{
	this->setSigned(obj.getSigned());
	this->setTarget(obj.getTarget());
	return (*this);
}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & obj) : Form("Default", 25, 5)
{
	*this = obj;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Default", 25, 5) { this->setTarget(target); }
PresidentialPardonForm::PresidentialPardonForm(void) : Form("Default", 25, 5) {}
PresidentialPardonForm::~PresidentialPardonForm(void) {}


void	PresidentialPardonForm::execute(Bureaucrat const & obj) const
{
	if (this->getSigned() == false)
		throw Form::NoSignedException();
	else if (obj.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
	else
		std::cout << this->getTarget() << " has been pardonned by Zafod Beeblebrox." << std::endl;
}
