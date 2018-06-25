#include "FragTrap.hpp"

void			FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (this->energy_points_ < ENERGY_COST)
	{
		std::cout << "FR4G-TP <" << this->name_ <<  "> Out of energy !" << std::endl;
		return ;
	}
	std::cout << "FR4G-TP <" << this->name_ << "> attacks <" + target + "> and screem ";
	this->energy_points_ -= ENERGY_COST;
	void (FragTrap::*f[F_SIZE])(void) = {
		&FragTrap::clapInTheBox,
		&FragTrap::gunWizard,
		&FragTrap::torgueFiesta,
		&FragTrap::pirateShipMode,
		&FragTrap::oneShotWonder
	};
	(this->*f[(rand() % F_SIZE)])();
}

void			FragTrap::clapInTheBox(void)
{
	std::cout << "\"This time it'll be awesome, I promise!\"" << std::endl;
}

void			FragTrap::gunWizard(void)
{
	std::cout << "\"Hey everybody, check out my package!\"" << std::endl;
}

void			FragTrap::torgueFiesta(void)
{
	std::cout << "\"Place your bets!\"" << std::endl;
}

void			FragTrap::pirateShipMode(void)
{
	std::cout << "\"Defragmenting!\"" << std::endl;
}

void			FragTrap::oneShotWonder(void)
{
	std::cout << "\"Recompiling my combat code!!\"" << std::endl;
}

FragTrap			&FragTrap::operator = (FragTrap const & obj)
{
	if (this != &obj)
		ClapTrap::operator=(obj);
	return (*this);
}

FragTrap::FragTrap(FragTrap const & obj)
{
	std::cout << "<FragTrap (" << this->name_ << ")> copy Constructor called" << std::endl;
	*this = obj;
}

FragTrap::FragTrap(std::string name) : ClapTrap(100, 100, 1, 30, 20, 5, name, 100, 100)
{
	std::cout << "<FragTrap (" << this->name_ << ")> overload Constructor called" << std::endl;
}

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "<FragTrap (" << this->name_ << ")> default Constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "<FragTrap> (" << this->name_ << ")> Destructor called" << std::endl;
}
