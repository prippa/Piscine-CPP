#ifndef PRINT_TYPE_HPP
# define PRINT_TYPE_HPP

# include <iostream>
# include <iomanip>
# include <cmath>

bool	isDigit(char d);
bool	isPrintable(char c);
int		toInt(double value);
char	toChar(double value);
void	printChar(double value);
void	printInt(double value);
void	printFloat(double value, int precision);
void	printDouble(double value, int precision);

#endif
