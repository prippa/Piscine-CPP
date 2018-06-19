#include <iostream>
#include <string>

int		main(void)
{
	std::string	str("HI THIS IS BRAIN");
	std::string	*pointer_str = &str;
	std::string	&reference_str = str;

	std::cout << "Pointer string: " << *pointer_str << std::endl;
	std::cout << "Reference string: " << reference_str << std::endl;
	return (0);
}
