#include "print_type.hpp"

bool	isDigit(char d)
{
	if (d >= '0' && d <= '9')
		return (true);
	return (false);
}

bool	isPrintable(char c)
{
	if (c >= 32 && c <= 126)
		return (true);
	return (false);
}

int		toInt(double value)
{
	int result = static_cast<int>(value);
	return (result);
}

char	toChar(double value)
{
	if (value < 0 || value > 127)
		return (-1);
	char result = static_cast<char>(value);
	return (result);
}

void	printChar(double value)
{
	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	char charRes = toChar(value);
	if (isPrintable(charRes))
		std::cout << "char: '"<< charRes << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void	printInt(double value)
{
	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	int intRes = toInt(value);
	std::cout << "int: "<< intRes << std::endl;
}

void	printFloat(double value, int precision)
{
	precision += (precision) ? 0 : 1;
	float floatRes = static_cast<float>(value);
	std::cout << "float: " << std::setprecision(precision) << std::fixed << floatRes << "f" << std::endl;
}

void	printDouble(double value, int precision)
{
	precision += (precision) ? 0 : 1;
	std::cout << "double: " << std::setprecision(precision) << std::fixed << value << std::endl;
}
