#include "FragTrap.hpp"

int		main(void)
{
	std::srand(std::time(0));

	FragTrap tmp("Prototype 4000");
	FragTrap ft("Prototype 1");
	
	ft = tmp;
	ft.rangedAttack("WTF?");
	ft.meleeAttack("WTF!");

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

	ft.vaulthunter_dot_exe("OLOLO");
	ft.vaulthunter_dot_exe("OLOLO");
	ft.vaulthunter_dot_exe("WTF1");
	ft.vaulthunter_dot_exe("WTF2");
	ft.vaulthunter_dot_exe("WTF3");
	ft.vaulthunter_dot_exe("WTF4");

	return (0);
}
