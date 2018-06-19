#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name_(name) {
	this->weapon_ = NULL;
}

HumanB::~HumanB(void) {}

void	HumanB::attack(void) {
	if (this->weapon_)
		std::cout << this->name_ << " attacks with his " << this->weapon_->getType();
	else
		std::cout << this->name_ << " does not have weapon!";
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon & weapon) {
	this->weapon_ = &weapon;
}
