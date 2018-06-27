#ifndef ARRAY_CLASS_HPP
# define ARRAY_CLASS_HPP

#include <stdexcept>

template <typename T = int>
class Array
{
private:
	T*				_array;
	unsigned int	_size;
public:

	Array<T>() : _array(NULL), _size(0) {};

	Array<T>(unsigned int n): _size(n)
	{
		if (_size == 0)
			_array = NULL;
		else
			_array = new T[n];
	};

	Array<T>(Array<T> const & src): _array(NULL), _size (0)
	{
		*this = src;
	};

	~Array<T>()
	{
		delete [] _array;
	};

	Array<T>	&operator = (Array<T> const & rhs)
	{
		if (this != &rhs)
		{
			delete [] this->_array;
			this->_size = rhs._size;
			this->_array = new T[rhs._size];
			for (unsigned int i = 0; i < rhs._size; ++i)
				this->_array[i] = rhs._array[i];
		}
		return (*this);
	};

	T	&operator [] (unsigned int num)
	{
		if (num < this->_size)
			return (this->_array[num]);
		else
			throw std::range_error("Segmentation fault!");
	};

	unsigned int	size() const
	{
		return (this->_size);
	};
};

#endif
