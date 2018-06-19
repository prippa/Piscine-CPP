#include "ZombieEvent.hpp"

int		main(void)
{
	std::srand(std::time(0));

	ZombieEvent	ze;
	Zombie		*z1;
	Zombie		*z2;
	Zombie		*z3;
	Zombie		*z4;

	z1 = ze.newZombie("Hang");
	ze.setZombieType("fast");
	z2 = ze.newZombie("Jeff");
	ze.setZombieType("slow");
	z3 = ze.newZombie("Ronald");
	z4 = ze.randomChump();

	std::cout << std::endl;

	delete (z1);
	delete (z2);
	z2->announce();
	delete (z3);
	delete (z4);
	return (0);
}
