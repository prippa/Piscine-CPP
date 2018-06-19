#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void) {
	this->type_ = "Default-type";
}

ZombieEvent::~ZombieEvent() {}

void	ZombieEvent::setZombieType(std::string type) {
	this->type_ = type;
}

Zombie	*ZombieEvent::newZombie(std::string name) {
	Zombie *zi = new Zombie(name, this->type_);

	return (zi);
}

Zombie	*ZombieEvent::randomChump(void) {
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
	Zombie *zi = new Zombie(name_buf[(rand() % 10)], this->type_);

	zi->announce();
	return (zi);
}
