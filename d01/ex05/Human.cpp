#include "Human.hpp"

Human::Human(void) {}

Human::~Human(void) {}

Brain		Human::getBrain(void) {
	return (this->brain_);
}

std::string	Human::identify(void) {
	return (this->brain_.identify());
}
