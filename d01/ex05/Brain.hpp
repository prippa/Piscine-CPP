#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <sstream>

class Brain
{
private:
	std::string	memory_address_;
public:
	Brain(void);
	~Brain(void);
	
	std::string	identify(void);
};

#endif
