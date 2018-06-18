#include "PhoneBook.class.hpp"
#include <cstdlib>

#define PB_SIZE 8

std::string	getLowerCaseString(std::string str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
	return (str);
}

void	phSearchLogic(PhoneBook ph[PB_SIZE], int size)
{
	std::string	tmp;
	int			index;

	if (!size)
	{
		std::cout << "The Phone Book is empty." << std::endl;
		return ;
	}
	std::cout << std::endl << "     Index|First name| Last name|  Nickname" << std::endl;
	for (int i = 0; i < size; ++i)
		ph[i].showBase(i + 1);
	std::cout << std::endl << "index -> ";
	std::getline(std::cin, tmp);
	index = atoi(tmp.c_str());
	if (index > 0 && index <= size)
	{
		std::cout << std::endl;
		ph[index - 1].showAll();
		std::cout << std::endl;
	}
}

int		phAddLogic(PhoneBook ph[PB_SIZE], int size)
{
	if (size == PB_SIZE)
	{
		std::cout << "The Phone Book is full!" << std::endl;
		return (0);
	}
	ph[size].add();
	return (1);
}

int		main(void)
{
	PhoneBook	ph[PB_SIZE];
	int			size = 0;
	std::string	cm;

	while (-42)
	{
		std::cout << "enter command -> ";
		std::getline(std::cin, cm);
		cm = getLowerCaseString(cm);
		if (cm == "add")
		{
			if (phAddLogic(ph, size))
				size++;
		}
		else if (cm == "search")
			phSearchLogic(ph, size);
		else if (cm == "exit")
			break ;
		else
			std::cout << "command not found: " << cm << std::endl;
	}
	return (0);
}
