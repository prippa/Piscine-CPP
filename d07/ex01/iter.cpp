#include <iostream>

template <typename T>
void	iter(T const * arr, size_t length, void(*f)(T const &))
{
	for (size_t i = 0; i < length; ++i)
	{
		f(arr[i]);
	}
}

template <typename T>
void	print_element(T const & elm)
{
	std::cout << elm << ' ';
}

int		main(void)
{
	int arr_int[] = {1, 2, 3, 42, 0, -42};
	std::string arr_string[] = {"Hello", "World", "!"};

	::iter(arr_int, 6, ::print_element);
	std::cout << std::endl;
	::iter(arr_string, 3, ::print_element);
	std::cout << std::endl;

	return (0);
}
