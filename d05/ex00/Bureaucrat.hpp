#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
private:
	std::string const	_name;
	int					_grade;
public:
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
