#include "PhoneBook.class.hpp"

std::string	PhoneBook::getOutputStr_(std::string str) const {
	if (str.size() > 10)
		return (str.substr(0, 9) + '.');
	return (str);
}

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
	<< std::setw(10) << this->getOutputStr_(this->first_name) << '|'
	<< std::setw(10) << this->getOutputStr_(this->last_name) << '|'
	<< std::setw(10) << this->getOutputStr_(this->nickname)
	<< std::endl;
}

void		PhoneBook::add(void) {
	std::cout << "Enter (first name)      -> ";
	std::getline(std::cin, this->first_name);
	std::cout << "Enter (last name)       -> ";
	std::getline(std::cin, this->last_name);
	std::cout << "Enter (nickname)        -> ";
	std::getline(std::cin, this->nickname);
	std::cout << "Enter (login)           -> ";
	std::getline(std::cin, this->login);
	std::cout << "Enter (postal address)  -> ";
	std::getline(std::cin, this->postal_address);
	std::cout << "Enter (email address)   -> ";
	std::getline(std::cin, this->email_address);
	std::cout << "Enter (phone number)    -> ";
	std::getline(std::cin, this->phone_number);
	std::cout << "Enter (birthday date)   -> ";
	std::getline(std::cin, this->birthday_date);
	std::cout << "Enter (favorite meal)   -> ";
	std::getline(std::cin, this->favorite_meal);
	std::cout << "Enter (underwear color) -> ";
	std::getline(std::cin, this->underwear_color);
	std::cout << "Enter (darkest secret)  -> ";
	std::getline(std::cin, this->darkest_secret);
}
