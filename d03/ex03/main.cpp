#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

int		main(void)
{
	std::srand(std::time(0));
	FragTrap fragT("f");
	ScavTrap scavT("s");
	NinjaTrap ninjaT("n");

	ninjaT.ninjaShoebox(fragT);
	ninjaT.ninjaShoebox(scavT);
	return (0);
}
