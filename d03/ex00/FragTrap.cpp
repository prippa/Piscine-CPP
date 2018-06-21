#include "FragTrap.hpp"

int const		FragTrap::max_hit_points_ = 100;
int const		FragTrap::max_energy_points_ = 100;
int const		FragTrap::level_ = 1;
int const		FragTrap::melee_attack_damage_ = 30;
int const		FragTrap::ranged_attack_damage_ = 20;
int const		FragTrap::armor_damage_reduction = 5;
int const		FragTrap::energy_cost_ = 25;

void			FragTrap::setEnergyPoints(unsigned int energy_points)
{
	if (energy_points > this->max_energy_points_)
		this->energy_points_ = this->max_energy_points_;
	else
		this->energy_points_ = energy_points;
}

unsigned int	FragTrap::getEnergyPoints(void)
{
	return (this->energy_points_);
}

void			FragTrap::setHitPoints(unsigned int hit_points)
{
	if (hit_points > this->max_hit_points_)
		this->hit_points_ = this->max_hit_points_;
	else
		this->hit_points_ = hit_points;
}

unsigned int	FragTrap::getHitPoints(void)
{
	return (this->hit_points_);
}

void			FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP <" + this->name_ + "> "
	<< "attacks <" + target + ">  at range, "
	<< "causing <" << this->ranged_attack_damage_
	<< "> points of damage !"
	<< std::endl;
}

void			FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP <" + this->name_ + "> "
	<< "attacks <" + target + ">  at melee, "
	<< "causing <" << this->melee_attack_damage_
	<< "> points of damage !"
	<< std::endl;
}

void			FragTrap::takeDamage(unsigned int amount)
{
	if (amount <= this->armor_damage_reduction)
		amount = 0;
	else
		amount -= this->armor_damage_reduction;
	std::cout << "FR4G-TP <" + this->name_ + "> with [" << this->hit_points_ << "] HP "
	<< "takes <" << amount << ">  damage ! ";
	if (this->hit_points_ < amount)
		this->hit_points_ = 0;
	else
		setHitPoints(this->hit_points_ - amount);
	std::cout << "now he have [" << this->hit_points_ << "]" << std::endl;
}

void			FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "FR4G-TP <" + this->name_ + "> with [" << this->hit_points_ << "] HP "
	<< "repaired himself by <" << amount << ">  HP ! ";
	setHitPoints(this->hit_points_ + amount);
	std::cout << "now he have [" << this->hit_points_ << "]" << std::endl;
}

void			FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (this->energy_points_ < this->energy_cost_)
	{
		std::cout << "FR4G-TP <" << this->name_ <<  "> Out of energy !" << std::endl;
		return ;
	}
	std::cout << "FR4G-TP <" << this->name_ << "> attacks <" + target + "> and screem ";
	this->energy_points_ -= this->energy_cost_;
	void (FragTrap::*f[F_SIZE])(void) = {
		&FragTrap::clapInTheBox,
		&FragTrap::gunWizard,
		&FragTrap::torgueFiesta,
		&FragTrap::pirateShipMode,
		&FragTrap::oneShotWonder
	};
	(this->*f[(rand() % F_SIZE)])();
}

void			FragTrap::clapInTheBox(void)
{
	std::cout << "\"This time it'll be awesome, I promise!\"" << std::endl;
}

void			FragTrap::gunWizard(void)
{
	std::cout << "\"Hey everybody, check out my package!\"" << std::endl;
}

void			FragTrap::torgueFiesta(void)
{
	std::cout << "\"Place your bets!\"" << std::endl;
}

void			FragTrap::pirateShipMode(void)
{
	std::cout << "\"Defragmenting!\"" << std::endl;
}

void			FragTrap::oneShotWonder(void)
{
	std::cout << "\"Recompiling my combat code!!\"" << std::endl;
}

void			FragTrap::operator = (FragTrap const & obj)
{
	this->hit_points_ = obj.hit_points_;
	this->energy_points_ = obj.energy_points_;
	this->name_ = obj.name_;
}

FragTrap::FragTrap(FragTrap const & obj)
{
	*this = obj;
}

FragTrap::FragTrap(std::string name) : hit_points_(100),
	energy_points_(100),
	name_(name)
{
	std::cout << "<FragTrap (" << this->name_ << ")> default Constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "<FragTrap> (" << this->name_ << ")> default Destructor called" << std::endl;
}
