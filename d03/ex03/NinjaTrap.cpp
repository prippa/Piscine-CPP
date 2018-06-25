#include "NinjaTrap.hpp"

void				NinjaTrap::ninjaShoebox(FragTrap & target)
{
	meleeAttack(target.getName());
	target.takeDamage(this->melee_attack_damage_);
}

void				NinjaTrap::ninjaShoebox(ScavTrap & target)
{
	meleeAttack(target.getName());
	target.takeDamage(this->melee_attack_damage_);
}

NinjaTrap			&NinjaTrap::operator = (NinjaTrap const & obj)
{
	if (this != &obj)
		ClapTrap::operator=(obj);
	return (*this);
}

NinjaTrap::NinjaTrap(NinjaTrap const & obj)
{
	*this = obj;
	std::cout << "<NinjaTrap (" << this->name_ << ")> copy Constructor called" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(120, 60, 1, 60, 5, 0, name, 60, 120)
{
	std::cout << "<NinjaTrap (" << this->name_ << ")> overload Constructor called" << std::endl;
}

NinjaTrap::NinjaTrap(void)
{
	this->name_ = "Default Name";
	std::cout << "<NinjaTrap> default Constructor called" << std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "<NinjaTrap> Destructor called" << std::endl;
}
