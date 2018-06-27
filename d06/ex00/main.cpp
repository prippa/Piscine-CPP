#include "print_type.hpp"

int	getPrecision(char *data)
{
	int len = static_cast<int>(strlen(data));
	bool dot_set = false;
	int i = 0;
	int precision = 0;

	if (data[i] == '-' || data[i] == '+')
		i++;
	while (i < len)
	{
		if (isDigit(data[i]))
			precision += dot_set;
		else if (data[i] == '.')
		{
			if (!dot_set)
				dot_set = true;
			else
				return (precision);
		}
		else
			return (precision);
		i++;
	}
	return (precision);
}

int		main(int argc, char **argv)
{
	double value;
	int	precision;

	for (int i = 1; i < argc; ++i)
	{
		precision = getPrecision(argv[i]);
		if (strlen(argv[i]) == 1 && isPrintable(argv[i][0]) && !isDigit(argv[i][0]))
			value = argv[i][0];
		else
			value = atof(argv[i]);
		printChar(value);
		printInt(value);
		printFloat(value, precision);
		printDouble(value, precision);
	}
	return (0);
}
