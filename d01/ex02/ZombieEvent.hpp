#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

# include "Zombie.hpp"

class ZombieEvent
{
private:
	std::string	type_;
public:
	ZombieEvent(void);
	~ZombieEvent(void);
	
	void		setZombieType(std::string type);
	Zombie* 	newZombie(std::string name);
	Zombie*		randomChump(void);
};

#endif
