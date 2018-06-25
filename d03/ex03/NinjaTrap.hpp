#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
public:

	void				ninjaShoebox(FragTrap & target);
	void				ninjaShoebox(ScavTrap & target);

	NinjaTrap			&operator = (NinjaTrap const & obj);
	NinjaTrap(NinjaTrap const & obj);
	NinjaTrap(std::string name);
	NinjaTrap(void);
	~NinjaTrap(void);
};

#endif
