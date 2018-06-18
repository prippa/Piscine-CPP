#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <iostream>
# include <iomanip>

class PhoneBook
{
private:
	std::string	getOutputStr_(std::string str) const;
public:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string postal_address;
	std::string email_address;
	std::string phone_number;
	std::string birthday_date;
	std::string favorite_meal;
	std::string underwear_color;
	std::string darkest_secret;

	PhoneBook(void);
	~PhoneBook(void);

	void		showAll(void) const;
	void		showBase(int index) const;
	void		add(void);
};

#endif
