#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat test1("P1", 150);
	Bureaucrat test2 = Bureaucrat();

	try
	{
		test1.downGrade();
	}
	catch (std::exception & e)
	{
		std::cout << test1 << std::endl;
		std::cout << e.what() << std::endl;
	}

	try
	{
		test2.upGrade();
	}
	catch (std::exception & e)
	{
		std::cout << test2 << std::endl;
		std::cout << e.what() << std::endl;
	}

	Bureaucrat test3;
	try
	{
		test3 = Bureaucrat("Name", -4242);
	}
	catch (std::exception & e)
	{
		std::cout << test3 << std::endl;
		std::cout << e.what() << std::endl;
	}

	Bureaucrat test4;
	try
	{
		test4 = Bureaucrat("Name", 4242);
	}
	catch (std::exception & e)
	{
		std::cout << test4 << std::endl;
		std::cout << e.what() << std::endl;
	}
	return (0);
}
