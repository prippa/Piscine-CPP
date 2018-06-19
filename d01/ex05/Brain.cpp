#include "Brain.hpp"

Brain::Brain(void) {
	std::stringstream mem;

	mem << this;
	this->memory_address_ = mem.str();
}

Brain::~Brain(void) {}

std::string	Brain::identify(void) {
	return (this->memory_address_);
}
