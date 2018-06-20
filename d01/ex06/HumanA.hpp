#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	Weapon & 	weapon_;
	std::string	name_;
public:
	void	attack(void);

	HumanA(std::string name, Weapon & weapon);
	~HumanA(void);
};

#endif
