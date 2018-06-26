#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const	_name;
	std::string			_target;
	bool				_signed;
	int	const			_sign_grade;
	int	const			_exec_grade;
public:
	virtual void	execute(Bureaucrat const & obj) const = 0;
	void			setTarget(std::string target);
	std::string		getTarget(void) const;

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
	class NoSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	void		beSigned(Bureaucrat & obj);

	bool		getSigned(void) const;
	void		setSigned(bool sig);

	std::string	getName(void) const;
	int			getSignGrade(void) const;
	int			getExecGrade(void) const;

	Form	&operator = (Form const & obj);

	Form(std::string name, int signg_grade, int exec_grade);
	Form(Form const & obj);
	Form(void);
	virtual ~Form(void);
};

std::ostream	&operator << (std::ostream & o, Form const & obj);

#endif
