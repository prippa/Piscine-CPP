#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) : name_(name), type_(type) {
	std::cout << "Zombie <" + this->name_ + " (" + this->type_ + ")> IS ALIVE!!!" << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "Zombie <" + this->name_ + " (" << this->type_ + ")> is died." << std::endl;
}

void	Zombie::announce(void) const {
	std::cout << "<" + this->name_ + " (" + this->type_ + ")> YABBA! MY ICECREAM NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO!!!!!!!!!!." << std::endl;
}
