#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"

class Human
{
private:
	Brain const	brain_;
public:
	Human(void);
	~Human(void);
	
	Brain		getBrain(void);
	std::string	identify(void);
};

#endif
