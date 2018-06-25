#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int		main(void)
{
	std::srand(std::time(0));
	std::cout << "-------------------FragTrap---------------------" << std::endl;
	{
		FragTrap tmp("Prototype 4000");
		FragTrap clap("Prototype 1");
		FragTrap ex = FragTrap();
		
		clap = tmp;
		clap.rangedAttack("WTF?");
		clap.meleeAttack("WTF!");

		clap.takeDamage(70);
		clap.takeDamage(30);
		clap.takeDamage(10);
		clap.takeDamage(7);
		clap.takeDamage(10);
		clap.takeDamage(-1);

		clap.beRepaired(104);
		clap.takeDamage(6);

		clap.beRepaired(10);
		clap.takeDamage(14);
		clap.takeDamage(150);
		clap.beRepaired(42);

		clap.vaulthunter_dot_exe("OLOLO");
		clap.vaulthunter_dot_exe("OLOLO");
		clap.vaulthunter_dot_exe("WTF1");
		clap.vaulthunter_dot_exe("WTF2");
		clap.vaulthunter_dot_exe("WTF3");
		clap.vaulthunter_dot_exe("WTF4");
	}
	std::cout << "-------------------ScavTrap---------------------" << std::endl;
	{
		ScavTrap tmp("Prototype 4001");
		ScavTrap clap("Prototype 1");
		ScavTrap ex = ScavTrap();

		clap = tmp;
		clap.rangedAttack("WTF42");
		clap.meleeAttack("WTF42");

		clap.takeDamage(70);
		clap.takeDamage(30);
		clap.takeDamage(10);
		clap.takeDamage(7);
		clap.takeDamage(10);
		clap.takeDamage(-1);

		clap.beRepaired(104);
		clap.takeDamage(6);

		clap.beRepaired(10);
		clap.takeDamage(14);
		clap.takeDamage(150);
		clap.beRepaired(42);

		clap.challengeNewcomer("WTF1");
		clap.challengeNewcomer("WTF2");
		clap.challengeNewcomer("WTF3");
		clap.challengeNewcomer("WTF4");
		clap.challengeNewcomer("WTF5");
		clap.challengeNewcomer("WTF6");
	}
	return (0);
}
