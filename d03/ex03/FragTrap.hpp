#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# define F_SIZE 5

class FragTrap : public ClapTrap
{
public:
	void				vaulthunter_dot_exe(std::string const & target);
	void				clapInTheBox(void);
	void				gunWizard(void);
	void				torgueFiesta(void);
	void				pirateShipMode(void);
	void				oneShotWonder(void);

	FragTrap			&operator = (FragTrap const & obj);
	FragTrap(FragTrap const & obj);
	FragTrap(std::string name);
	FragTrap(void);
	~FragTrap(void);
};

#endif
