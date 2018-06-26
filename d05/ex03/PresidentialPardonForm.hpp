#ifndef PRESIDENTIAL_PARDOM_FORM_HPP
# define PRESIDENTIAL_PARDOM_FORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
	void	execute(Bureaucrat const & obj) const;

	PresidentialPardonForm	&operator = (PresidentialPardonForm const & obj);
	PresidentialPardonForm(PresidentialPardonForm const & obj);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(void);
	~PresidentialPardonForm(void);
};

#endif
