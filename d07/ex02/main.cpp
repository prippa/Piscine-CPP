#include <iostream>
#include "Array.class.tpp"

int		main(void)
{
	Array<std::string> arr_str = Array<std::string>(3);

	arr_str[0] = "Hello";
	arr_str[1] = "World";
	arr_str[2] = "!";

	std::cout << arr_str[0] << " " << arr_str[1] << " " << arr_str[2] << " " << std::endl;

	Array<> arr_default = Array<>(5);

	arr_default[0] = 1;
	arr_default[1] = 11;
	arr_default[2] = -42;
	arr_default[3] = 42;
	arr_default[4] = 0;

	std::cout << arr_default[0] << " " << arr_default[1] << " " << arr_default[2] << " " << arr_default[3] << " " << arr_default[4] << " " << std::endl;
	
	try
	{
		arr_default[+42] = -42;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}
