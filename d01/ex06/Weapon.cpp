#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type_(type) {}
Weapon::~Weapon(void) {}

std::string const & Weapon::getType(void){
	return (this->type_);
}

void				Weapon::setType(std::string type) {
	this->type_ = type;
}
