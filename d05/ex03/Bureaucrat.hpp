#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	std::string const	_name;
	int					_grade;
public:
	void	executeForm(Form const & form) const;
	void	signForm(Form & f);

	void	upGrade(void);
	void	downGrade(void);

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

	std::string	getName(void) const;
	int			getGrade(void) const;

	Bureaucrat &operator = (Bureaucrat const & obj);
	Bureaucrat(Bureaucrat const & obj);
	Bureaucrat(std::string const name, int const grade);
	Bureaucrat(void);
	~Bureaucrat(void);
};

std::ostream	&operator << (std::ostream & o, Bureaucrat const & obj);

#endif
