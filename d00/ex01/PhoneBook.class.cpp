#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) {}
PhoneBook::~PhoneBook(void) {}

void		PhoneBook::showAll(void) const {
	std::cout << "first name      : " << this->first_name << std::endl;
	std::cout << "last name       : " << this->last_name << std::endl;
	std::cout << "nickname        : " << this->nickname << std::endl;
	std::cout << "login           : " << this->login << std::endl;
	std::cout << "postal address  : " << this->postal_address << std::endl;
	std::cout << "email address   : " << this->email_address << std::endl;
	std::cout << "phone number    : " << this->phone_number << std::endl;
	std::cout << "birthday date   : " << this->birthday_date << std::endl;
	std::cout << "favorite meal   : " << this->favorite_meal << std::endl;
	std::cout << "underwear color : " << this->underwear_color << std::endl;
	std::cout << "darkest secret  : " << this->darkest_secret << std::endl;
}

void		PhoneBook::showBase(int index) const {
	std::cout
	<< std::setw(10) << index << '|'
	<< std::setw(10) << getOutputStr(this->first_name) << '|'
	<< std::setw(10) << getOutputStr(this->last_name) << '|'
	<< std::setw(10) << getOutputStr(this->nickname)
	<< std::endl;
}

void		PhoneBook::add(void) {
	std::cout << "Enter (first name)      -> ";
	ft_getline(this->first_name);
	std::cout << "Enter (last name)       -> ";
	ft_getline(this->last_name);
	std::cout << "Enter (nickname)        -> ";
	ft_getline(this->nickname);
	std::cout << "Enter (login)           -> ";
	ft_getline(this->login);
	std::cout << "Enter (postal address)  -> ";
	ft_getline(this->postal_address);
	std::cout << "Enter (email address)   -> ";
	ft_getline(this->email_address);
	std::cout << "Enter (phone number)    -> ";
	ft_getline(this->phone_number);
	std::cout << "Enter (birthday date)   -> ";
	ft_getline(this->birthday_date);
	std::cout << "Enter (favorite meal)   -> ";
	ft_getline(this->favorite_meal);
	std::cout << "Enter (underwear color) -> ";
	ft_getline(this->underwear_color);
	std::cout << "Enter (darkest secret)  -> ";
	ft_getline(this->darkest_secret);
}
