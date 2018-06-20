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
	// Six comparison operators
	bool				operator > (Fixed const & obj) const;
	bool				operator < (Fixed const & obj) const;
	bool				operator >= (Fixed const & obj) const;
	bool				operator <= (Fixed const & obj) const;
	bool				operator == (Fixed const & obj) const;
	bool				operator != (Fixed const & obj) const;

	// Four arithmetic operators
	Fixed				operator + (Fixed const & obj) const;
	Fixed				operator - (Fixed const & obj) const;
	Fixed				operator * (Fixed const & obj) const;
	Fixed				operator / (Fixed const & obj) const;

	// Increment Decrement
	Fixed				&operator ++ (void);
	Fixed				operator ++ (int);
	Fixed				&operator -- (void);
	Fixed				operator -- (int);

	// max min
	static Fixed		&min(Fixed & a, Fixed & b);
	static Fixed const	&min(Fixed const & a, Fixed const & b);
	static Fixed		&max(Fixed & a, Fixed & b);
	static Fixed const	&max(Fixed const & a, Fixed const & b);

	void				operator = (Fixed const & obj);

	float				toFloat(void) const;
	int					toInt(void) const;
	int 				getRawBits(void) const;
	void				setRawBits(int const raw);

	Fixed(int const & val);
	Fixed(float const & val);
	Fixed(Fixed const & obj);
	Fixed(void);
	~Fixed(void);
};

std::ostream	&operator << (std::ostream & os, Fixed const & obj);

#endif
