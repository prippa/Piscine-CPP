#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie(void) {
	std::cout << "Zombie <" + this->name + "> is died." << std::endl;
}

void	Zombie::announce(void) const {
	std::cout << "<" + this->name + "> YABBA! MY ICECREAM NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO!!!!!!!!!﻿." << std::endl;
}
