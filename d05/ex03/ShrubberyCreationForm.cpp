#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm	&ShrubberyCreationForm::operator = (ShrubberyCreationForm const & obj)
{
	this->setSigned(obj.getSigned());
	this->setTarget(obj.getTarget());
	return (*this);
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & obj) : Form("Default", 145, 137)
{
	*this = obj;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Default", 145, 137) { this->setTarget(target); }
ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("Default", 145, 137) {}
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

const char*	ShrubberyCreationForm::CantOpenFile::what() const throw()
{
	return ("ShrubberyCreationForm: Cant Open File !");
}


void	ShrubberyCreationForm::execute(Bureaucrat const & obj) const
{
	if (this->getSigned() == false)
		throw Form::NoSignedException();
	else if (obj.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
	else
	{
		std::ofstream ofs;
		std::string name(this->getTarget() + "_shrubbery");
		ofs.open(name.c_str());
		if (!ofs.is_open())
			throw ShrubberyCreationForm::CantOpenFile();
		else
			ofs << RETRO_TREE << std::endl;
		ofs.close();
	}
}
