#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Intern someRandomIntern;

	Form* rrf;
	Form* scf;
	Form* ppf;
	Form* unk;
	
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << "Target: " << rrf->getTarget() << std::endl;

	scf = someRandomIntern.makeForm("shrubbery creation", "Bobby");
	std::cout << "Target: " << scf->getTarget() << std::endl;

	ppf = someRandomIntern.makeForm("presidential pardon", "Billy");
	std::cout << "Target: " << ppf->getTarget() << std::endl;

	std::cout << std::endl;
	unk = someRandomIntern.makeForm("?!?!?!?", "#####");


	delete rrf;
	delete scf;
	delete ppf;

	return (0);
}
