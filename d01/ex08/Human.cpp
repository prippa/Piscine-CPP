#include "Human.hpp"

void	Human::meleeAttack(std::string const & target) {
	std::cout << "meleeAttack to " << target << std::endl;
}

void	Human::rangedAttack(std::string const & target) {
	std::cout << "rangedAttack to " << target << std::endl;
}

void	Human::intimidatingShout(std::string const & target) {
	std::cout << "intimidatingShout to " << target << std::endl;
}

void	Human::action(std::string const &action_name, std::string const &target) {
	void (Human::*f[FUNC_SIZE])(std::string const & t) = {
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};
	std::string an_arr[FUNC_SIZE] = {
		"meleeAttack",
		"rangedAttack",
		"intimidatingShout"
	};
	for (int i = 0; i < FUNC_SIZE; ++i)
	{
		if (an_arr[i] == action_name)
			(this->*f[i])(target);
	}
}
