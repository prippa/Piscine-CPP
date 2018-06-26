#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
	void	execute(Bureaucrat const & obj) const;

	RobotomyRequestForm	&operator = (RobotomyRequestForm const & obj);
	RobotomyRequestForm(RobotomyRequestForm const & obj);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(void);
	~RobotomyRequestForm(void);
};

#endif
