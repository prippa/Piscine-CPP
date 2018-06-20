#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					raw_;
	static const int	bits_ = 8;
public:
	void			operator = (Fixed const & obj);
	float			toFloat(void) const;
	int				toInt(void) const;
	int 			getRawBits(void) const;
	void			setRawBits(int const raw);

	Fixed(int const & val);
	Fixed(float const & val);
	Fixed(Fixed const & obj);
	Fixed(void);
	~Fixed(void);
};

std::ostream	&operator << (std::ostream & os, Fixed const & obj);

#endif
