#include "ScavTrap.hpp"

int const		ScavTrap::max_hit_points_ = 100;
int const		ScavTrap::max_energy_points_ = 50;
int const		ScavTrap::level_ = 1;
int const		ScavTrap::melee_attack_damage_ = 20;
int const		ScavTrap::ranged_attack_damage_ = 15;
int const		ScavTrap::armor_damage_reduction = 3;
int const		ScavTrap::energy_cost_ = 25;

void			ScavTrap::setEnergyPoints(unsigned int energy_points)
{
	if (energy_points > this->max_energy_points_)
		this->energy_points_ = this->max_energy_points_;
	else
		this->energy_points_ = energy_points;
}

unsigned int	ScavTrap::getEnergyPoints(void)
{
	return (this->energy_points_);
}

void			ScavTrap::setHitPoints(unsigned int hit_points)
{
	if (hit_points > this->max_hit_points_)
		this->hit_points_ = this->max_hit_points_;
	else
		this->hit_points_ = hit_points;
}

unsigned int	ScavTrap::getHitPoints(void)
{
	return (this->hit_points_);
}

void			ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "SC4V-TP <" + this->name_ + "> "
	<< "attacks <" + target + ">  at range, "
	<< "causing <" << this->ranged_attack_damage_
	<< "> points of damage !"
	<< std::endl;
}

void			ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "SC4V-TP <" + this->name_ + "> "
	<< "attacks <" + target + ">  at melee, "
	<< "causing <" << this->melee_attack_damage_
	<< "> points of damage !"
	<< std::endl;
}

void			ScavTrap::takeDamage(unsigned int amount)
{
	if (amount <= this->armor_damage_reduction)
		amount = 0;
	else
		amount -= this->armor_damage_reduction;
	std::cout << "SC4V-TP <" + this->name_ + "> with [" << this->hit_points_ << "] HP "
	<< "takes <" << amount << ">  damage ! ";
	if (this->hit_points_ < amount)
		this->hit_points_ = 0;
	else
		setHitPoints(this->hit_points_ - amount);
	std::cout << "now he have [" << this->hit_points_ << "]" << std::endl;
}

void			ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "SC4V-TP <" + this->name_ + "> with [" << this->hit_points_ << "] HP "
	<< "repaired himself by <" << amount << ">  HP ! ";
	setHitPoints(this->hit_points_ + amount);
	std::cout << "now he have [" << this->hit_points_ << "]" << std::endl;
}

void			ScavTrap::challengeNewcomer(std::string const & target)
{
	if (this->energy_points_ < this->energy_cost_)
	{
		std::cout << "SC4V-TP <" << this->name_ <<  "> Out of energy !" << std::endl;
		return ;
	}
	std::cout << "SC4V-TP <" << this->name_ << "> attacks <" + target + "> and screem ";
	this->energy_points_ -= this->energy_cost_;
	void (ScavTrap::*f[F_SIZE])(void) = {
		&ScavTrap::laserInferno,
		&ScavTrap::miniontrap,
		&ScavTrap::meatUnicycle,
		&ScavTrap::funzerker,
		&ScavTrap::mechromagician
	};
	(this->*f[(rand() % F_SIZE)])();
}

void			ScavTrap::laserInferno(void)
{
	std::cout << "\"Running the sequencer!\"" << std::endl;
}

void			ScavTrap::miniontrap(void)
{
	std::cout << "\"It's happening... it's happening!\"" << std::endl;
}

void			ScavTrap::meatUnicycle(void)
{
	std::cout << "\"It's about to get magical!\"" << std::endl;
}

void			ScavTrap::funzerker(void)
{
	std::cout << "\"I'm pulling tricks outta my hat!\"" << std::endl;
}

void			ScavTrap::mechromagician(void)
{
	std::cout << "\"You can't just program this level of excitement!\"" << std::endl;
}

void			ScavTrap::operator = (ScavTrap const & obj)
{
	this->hit_points_ = obj.hit_points_;
	this->energy_points_ = obj.energy_points_;
	this->name_ = obj.name_;
}

ScavTrap::ScavTrap(ScavTrap const & obj)
{
	*this = obj;
}

ScavTrap::ScavTrap(std::string name) : hit_points_(100),
	energy_points_(50),
	name_(name)
{
	std::cout << "<ScavTrap (" << this->name_ << ")> default Constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "<ScavTrap> (" << this->name_ << ")> default Destructor called" << std::endl;
}
