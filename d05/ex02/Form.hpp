#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const	_name;
	bool				_signed;
	int	const			_sign_grade;
	int	const			_exec_grade;
public:
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	void		beSigned(Bureaucrat & obj);
	void		setSigned();

	std::string	getName(void) const;
	bool		getSigned(void) const;
	int			getSignGrade(void) const;
	int			getExecGrade(void) const;

	Form	&operator = (Form const & obj);

	Form(std::string name, int signg_grade, int exec_grade);
	Form(Form const & obj);
	Form(void);
	~Form(void);
};

std::ostream	&operator << (std::ostream & o, Form const & obj);

#endif
