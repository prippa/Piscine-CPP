#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# define F_SIZE 5

class ScavTrap : public ClapTrap
{
public:
	void				challengeNewcomer(std::string const & target);
	void				laserInferno(void);
	void				miniontrap(void);
	void				meatUnicycle(void);
	void				funzerker(void);
	void				mechromagician(void);

	ScavTrap			&operator = (ScavTrap const & obj);
	ScavTrap(ScavTrap const & obj);
	ScavTrap(std::string name);
	ScavTrap(void);
	~ScavTrap(void);
};

#endif
