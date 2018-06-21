#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# define F_SIZE 5

class ScavTrap
{
private:
	static const int	max_energy_points_;
	static const int	max_hit_points_;
	static const int	level_;
	static const int	melee_attack_damage_;
	static const int	ranged_attack_damage_;
	static const int	armor_damage_reduction;
	static const int	energy_cost_;
	unsigned int		hit_points_;
	unsigned int		energy_points_;
	std::string			name_;
public:
	void				setEnergyPoints(unsigned int energy_points);
	unsigned int		getEnergyPoints(void);

	void				setHitPoints(unsigned int hit_points);
	unsigned int		getHitPoints(void);

	std::string			getName(void);

	void				rangedAttack(std::string const & target);
	void				meleeAttack(std::string const & target);
	void				takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);

	void				challengeNewcomer(std::string const & target);
	void				laserInferno(void);
	void				miniontrap(void);
	void				meatUnicycle(void);
	void				funzerker(void);
	void				mechromagician(void);

	void				operator = (ScavTrap const & obj);
	ScavTrap(ScavTrap const & obj);
	ScavTrap(std::string name);
	~ScavTrap(void);
};

#endif
