#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"

class Form;

class Intern
{
public:
	Intern & operator = (Intern const & obj);
	Intern(Intern const & obj);
	Intern(void);
	~Intern(void);

	Form * makeForm(std::string form, std::string target);
};

#endif
