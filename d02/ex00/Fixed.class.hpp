#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>

class Fixed
{
private:
	int					raw_;
	static const int	bits_;
public:
	void	operator = (Fixed const & obj);
	int 	getRawBits(void) const;
	void	setRawBits(int const raw); 

	Fixed(Fixed const & obj);
	Fixed(void);
	~Fixed(void);
};

#endif