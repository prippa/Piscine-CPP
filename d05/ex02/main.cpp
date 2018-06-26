#include "Form.hpp"

int main(void)
{
	std::cout << "---------Bureaucrat------------" << std::endl;
	Bureaucrat b1("Big_Boss", 1);
	Bureaucrat expert("Expert", 15);
	Bureaucrat intern("Intern", 150);

	std::cout << b1 << std::endl;
	std::cout << expert << std::endl;
	std::cout << intern << std::endl;

	std::cout << "---------Forms------------" << std::endl;
	Form f_b1("from Big_Boss for Experts", 1, 15);
	Form f_expert("from Experts for Interns", 15, 150);

	std::cout << f_b1 << std::endl;
	std::cout << f_expert << std::endl;

	std::cout << "---------try | catch------------" << std::endl;
	try
	{
		f_b1.beSigned(expert);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		intern.signForm(f_expert);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		b1.signForm(f_expert);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		b1.signForm(f_b1);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
