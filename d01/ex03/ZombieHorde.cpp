#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n) : size_(n) {
	std::string name_buf[] = {
		"James",
		"John",
		"Robert",
		"Michael",
		"William",
		"David",
		"Richard",
		"Charles",
		"Joseph",
		"Thomas"
	};

	this->hoard_ = new Zombie[size_];
	for (int i = 0; i < size_; ++i)
		hoard_[i].name = name_buf[(rand() % 10)];
}

ZombieHorde::~ZombieHorde(void) {
	delete [] (hoard_);
}

void	ZombieHorde::announce(void) const {
	for (int i = 0; i < size_; ++i)
		hoard_[i].announce();
}
