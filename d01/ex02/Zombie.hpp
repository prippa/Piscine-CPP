#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
private:
	std::string name_;
	std::string type_;
public:
	Zombie(std::string name, std::string type);
	~Zombie(void);
	
	void		announce(void) const;
};

#endif
