#include "Fixed.class.hpp"

int const Fixed::bits_ = 8;

void	Fixed::operator = (Fixed const & obj)
{
	std::cout << "Assignation operator called" << std::endl;
	this->raw_ = obj.getRawBits();
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->raw_);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->raw_ = raw;
}

Fixed::Fixed(Fixed const & obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(void) : raw_(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
};
