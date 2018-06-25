#include "ScavTrap.hpp"

void			ScavTrap::challengeNewcomer(std::string const & target)
{
	if (this->energy_points_ < ENERGY_COST)
	{
		std::cout << "SC4V-TP <" << this->name_ <<  "> Out of energy !" << std::endl;
		return ;
	}
	std::cout << "SC4V-TP <" << this->name_ << "> attacks <" + target + "> and screem ";
	this->energy_points_ -= ENERGY_COST;
	void (ScavTrap::*f[F_SIZE])(void) = {
		&ScavTrap::laserInferno,
		&ScavTrap::miniontrap,
		&ScavTrap::meatUnicycle,
		&ScavTrap::funzerker,
		&ScavTrap::mechromagician
	};
	(this->*f[(rand() % F_SIZE)])();
}

void			ScavTrap::laserInferno(void)
{
	std::cout << "\"Running the sequencer!\"" << std::endl;
}

void			ScavTrap::miniontrap(void)
{
	std::cout << "\"It's happening... it's happening!\"" << std::endl;
}

void			ScavTrap::meatUnicycle(void)
{
	std::cout << "\"It's about to get magical!\"" << std::endl;
}

void			ScavTrap::funzerker(void)
{
	std::cout << "\"I'm pulling tricks outta my hat!\"" << std::endl;
}

void			ScavTrap::mechromagician(void)
{
	std::cout << "\"You can't just program this level of excitement!\"" << std::endl;
}

ScavTrap			&ScavTrap::operator = (ScavTrap const & obj)
{
	if (this != &obj)
		ClapTrap::operator=(obj);
	return (*this);
}

ScavTrap::ScavTrap(ScavTrap const & obj)
{
	*this = obj;
	std::cout << "<ScavTrap (" << this->name_ << ")> copy Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(50, 100, 1, 20, 15, 3, name, 100, 50)
{
	std::cout << "<ScavTrap (" << this->name_ << ")> overload Constructor called" << std::endl;
}

ScavTrap::ScavTrap(void)
{
	std::cout << "<ScavTrap (" << this->name_ << ")> default Constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "<ScavTrap> (" << this->name_ << ")> Destructor called" << std::endl;
}
