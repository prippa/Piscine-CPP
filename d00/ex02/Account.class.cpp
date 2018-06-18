#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.class.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void			Account::_displayTimestamp(void) {
	std::time_t	t;
	std::tm		*gmt;

	t = std::time(0);
	gmt = std::gmtime(&t);
	// cout block
	std::cout << "[" << gmt->tm_year + 1900
	<< std::setfill('0') << std::setw(2) << gmt->tm_mon + 1
	<< std::setfill('0') << std::setw(2) << gmt->tm_mday << "_"
	<< std::setfill('0') << std::setw(2) << gmt->tm_hour
	<< std::setfill('0') << std::setw(2) << gmt->tm_min
	<< std::setfill('0') << std::setw(2) << gmt->tm_sec << "] ";
}

Account::Account (int initial_deposit) : _amount(initial_deposit) {
	Account::_displayTimestamp();
	// cout block
	std::cout
	<< "index:" << Account::_nbAccounts
	<< ";amount:" << this->_amount
	<< ";created"
	<< std::endl;
	this->_accountIndex = Account::_nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;
}

Account::~Account() {
	Account::_nbAccounts--;
	Account::_displayTimestamp();
	// cout block
	std::cout << "index:" << Account::_nbAccounts
	<< ";amount:" << this->_amount
	<< ";closed"
	<< std::endl;
}

int				Account::getNbAccounts(void) { return (Account::_nbAccounts); }
int				Account::getTotalAmount(void) { return (Account::_totalAmount); }
int				Account::getNbDeposits(void) { return (Account::_totalNbDeposits); }
int				Account::getNbWithdrawals(void) { return (Account::_totalNbWithdrawals); }

void			Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	// cout block
	std::cout << "accounts:" << Account::_nbAccounts
	<< ";total:" << Account::_totalAmount
	<< ";deposits:" << Account::_totalNbDeposits
	<< ";withdrawals:" << Account::_totalNbWithdrawals
	<< std::endl;
}

void			Account::displayStatus (void) const {
	Account::_displayTimestamp();
	// cout block
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";deposits:" << this->_nbDeposits
	<< ";withdrawals:" << this->_nbWithdrawals
	<< std::endl;
}

void			Account::makeDeposit(int deposit) {
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_displayTimestamp();
	// cout block
	std::cout << "index:" << this->_accountIndex
	<< ";p_amount:" << this->_amount - deposit
	<< ";deposit:" << deposit
	<< ";amount:" << this->_amount
	<< ";nb_deposits:" << this->_nbDeposits
	<< std::endl;
}

int				Account::checkAmount(void) const {
	return (this->_amount);
}

bool			Account::makeWithdrawal(int withdrawal) {
	std::string	str;

	str = "index:" + std::to_string(this->_accountIndex) +
	";p_amount:" + std::to_string(this->_amount) + ";withdrawal:";
	Account::_displayTimestamp();
	if (this->checkAmount() < withdrawal)
	{
		str += "refused";
		//cout
		std::cout << str << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	str += std::to_string(withdrawal) + ";amount:" +
	std::to_string(this->_amount) + ";nb_withdrawals:" +
	std::to_string(this->_nbWithdrawals);
	// cout
	std::cout << str << std::endl;
	return (true);
}
