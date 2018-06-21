#include "ScavTrap.hpp"

int		main(void)
{
	std::srand(std::time(0));

	ScavTrap tmp("Prototype 4001");
	ScavTrap ft("Prototype 1");
	
	ft = tmp;
	ft.rangedAttack("WTF42");
	ft.meleeAttack("WTF42");

	ft.takeDamage(70);
	ft.takeDamage(30);
	ft.takeDamage(10);
	ft.takeDamage(7);
	ft.takeDamage(10);
	ft.takeDamage(-1);

	ft.beRepaired(104);
	ft.takeDamage(6);

	ft.beRepaired(10);
	ft.takeDamage(14);
	ft.takeDamage(150);
	ft.beRepaired(42);

	ft.challengeNewcomer("WTF1");
	ft.challengeNewcomer("WTF2");
	ft.challengeNewcomer("WTF3");
	ft.challengeNewcomer("WTF4");
	ft.challengeNewcomer("WTF5");
	ft.challengeNewcomer("WTF6");

	return (0);
}
