#include "ZombieHorde.hpp"

int		main(void)
{
	std::srand(std::time(0));

	ZombieHorde zh(42);

	zh.announce();
	return (0);
}
