#include "ClapTrap.hpp"

void			ClapTrap::setMaxEnergyPoints(int max_energy_points) { this->max_energy_points_ = max_energy_points; }
int				ClapTrap::getMaxEnergyPoints(void) { return (this->max_energy_points_); }

void			ClapTrap::setMaxHitPoints(int max_hit_points) { this->max_hit_points_ = max_hit_points; }
int				ClapTrap::getMaxHitPoints(void) { return (this->max_hit_points_); }

void			ClapTrap::setLevel(int level) { this->level_ = level; }
int				ClapTrap::getLevel(void) { return (this->level_); }

void			ClapTrap::setMeleeAttackDamage(int melee_attack_damage) { this->melee_attack_damage_ = melee_attack_damage; }
int				ClapTrap::getMeleeAttackDamage(void) { return (this->melee_attack_damage_); }

void			ClapTrap::setRangeAttackDamage(int ranged_attack_damage) { this->ranged_attack_damage_ = ranged_attack_damage; }
int				ClapTrap::getRangeAttackDamage(void) { return (this->ranged_attack_damage_); }

void			ClapTrap::setArmorDamageReduction(int armor_damage_reduction) { this->armor_damage_reduction_ = armor_damage_reduction; }
int				ClapTrap::getArmorDamageReduction(void) { return (this->armor_damage_reduction_); }

void			ClapTrap::setName(int name) { this->name_ = name; }
std::string		ClapTrap::getName(void) { return (this->name_); }

void			ClapTrap::setEnergyPoints(unsigned int energy_points)
{
	if (energy_points > this->max_energy_points_)
		this->energy_points_ = this->max_energy_points_;
	else
		this->energy_points_ = energy_points;
}

unsigned int	ClapTrap::getEnergyPoints(void)
{
	return (this->energy_points_);
}

void			ClapTrap::setHitPoints(unsigned int hit_points)
{
	if (hit_points > this->max_hit_points_)
		this->hit_points_ = this->max_hit_points_;
	else
		this->hit_points_ = hit_points;
}

unsigned int	ClapTrap::getHitPoints(void)
{
	return (this->hit_points_);
}

void			ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << "ClapTrap <" + this->name_ + "> "
	<< "attacks <" + target + ">  at range, "
	<< "causing <" << this->ranged_attack_damage_
	<< "> points of damage !"
	<< std::endl;
}

void			ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << "ClapTrap <" + this->name_ + "> "
	<< "attacks <" + target + ">  at melee, "
	<< "causing <" << this->melee_attack_damage_
	<< "> points of damage !"
	<< std::endl;
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	if (amount <= this->armor_damage_reduction_)
		amount = 0;
	else
		amount -= this->armor_damage_reduction_;
	std::cout << "ClapTrap <" + this->name_ + "> with [" << this->hit_points_ << "] HP "
	<< "takes <" << amount << ">  damage ! ";
	if (this->hit_points_ < amount)
		this->hit_points_ = 0;
	else
		setHitPoints(this->hit_points_ - amount);
	std::cout << "now he have [" << this->hit_points_ << "]" << std::endl;
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap <" + this->name_ + "> with [" << this->hit_points_ << "] HP "
	<< "repaired himself by <" << amount << ">  HP ! ";
	setHitPoints(this->hit_points_ + amount);
	std::cout << "now he have [" << this->hit_points_ << "]" << std::endl;
}

ClapTrap::ClapTrap(int max_energy_points, int max_hit_points,
			int level, int melee_attack_damage, int ranged_attack_damage,
			int armor_damage_reduction, std::string name,
			unsigned int hit_points, unsigned int energy_points)
{
	this->max_energy_points_ = max_energy_points;
	this->max_hit_points_ = max_hit_points;
	this->level_ = level;
	this->melee_attack_damage_ = melee_attack_damage;
	this->ranged_attack_damage_ = ranged_attack_damage;
	this->armor_damage_reduction_ = armor_damage_reduction;
	this->name_ = name;
	this->hit_points_ = hit_points;
	this->energy_points_ = energy_points;
	std::cout << "<ClapTrap> overload Constructor called" << std::endl;
}

ClapTrap			&ClapTrap::operator = (ClapTrap const & obj)
{
	if (this != &obj)
	{
		this->max_energy_points_ = obj.max_energy_points_;
		this->max_hit_points_ = obj.max_hit_points_;
		this->level_ = obj.level_;
		this->melee_attack_damage_ = obj.melee_attack_damage_;
		this->ranged_attack_damage_ = obj.ranged_attack_damage_;
		this->armor_damage_reduction_ = obj.armor_damage_reduction_;
		this->name_ = obj.name_;
		this->hit_points_ = obj.hit_points_;
		this->energy_points_ = obj.energy_points_;
	}
	return (*this);
}

ClapTrap::ClapTrap(ClapTrap const & obj)
{
	*this = obj;
	std::cout << "<ClapTrap> copy Constructor called" << std::endl;
}

ClapTrap::ClapTrap(void)
{
	this->name_ = "Default Name";
	std::cout << "<ClapTrap> default Constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "<ClapTrap> Destructor called" << std::endl;
}
