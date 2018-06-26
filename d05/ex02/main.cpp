#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	srand(time(NULL));

	std::cout << "/************ Forms execution ************\\" << std::endl;

	std::cout << std::endl << "---> Create 2 Bureaucrat (Mike lvl 1 and John lvl 62)." <<std::endl;
	Bureaucrat Buro1 = Bureaucrat("Mike", 1);
	Bureaucrat Buro2 = Bureaucrat("John", 62);

	std::cout << "---> Create 3 forms with target names." <<std::endl;
	PresidentialPardonForm PForm = PresidentialPardonForm("President");
	ShrubberyCreationForm SForm = ShrubberyCreationForm("Retro");
	RobotomyRequestForm RForm = RobotomyRequestForm("Bender");

	std::cout << std::endl << "---> Execute Robot form (50% chances of success):" <<std::endl;
	RForm.setSigned(true);
	//exec robot
	try
	{
		RForm.execute(Buro1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	//exec president not signed form
	std::cout << std::endl << "---> Execute Presidential form (not signed):" <<std::endl;
	try
	{
		PForm.execute(Buro1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	//exec president signed form
	std::cout << std::endl << "---> Sign & execute Presidential form:" <<std::endl;
	PForm.setSigned(true);
	try
	{
		PForm.execute(Buro1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	// create tree file
	std::cout << std::endl << "---> Sign & execute Shrubbery form:" <<std::endl;
	SForm.setSigned(true);
	try
	{
		SForm.execute(Buro1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "(<target>_shrubbery file created)" << std::endl;
	// fail form FROM bureaucrat
	std::cout << std::endl << "---> John fail to sign Presidential form:" <<std::endl;
	try
	{
		Buro2.executeForm(PForm);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	// exec president form from bureaucrat
	std::cout << std::endl << "---> Mike execute Presidential form:" <<std::endl;
	try
	{
		Buro1.executeForm(PForm);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
    // fail exec from form
	std::cout << std::endl << "---> John fail to execute Shrubbery form:" <<std::endl;
    try
    {
		PForm.execute(Buro2);
    }
    catch (std::exception & e)
    {
		std::cout << e.what() << std::endl;
    }
    // fail exec from form
	std::cout << std::endl << "---> John fail to execute Robot form:" <<std::endl;
    try
    {
		RForm.execute(Buro2);
    }
    catch (std::exception & e)
    {
		std::cout << e.what() << std::endl;
    }
	return (0);
}
