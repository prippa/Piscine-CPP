#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	Weapon *	weapon_;
	std::string	name_;
public:
	void	attack(void);
	void	setWeapon(Weapon & weapon);

	HumanB(std::string name);
	~HumanB(void);
};

#endif