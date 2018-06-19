#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	std::string type_;
public:
	std::string const & getType(void);
	void				setType(std::string type);

	Weapon(std::string type);
	~Weapon(void);
};

#endif
