#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# define ENERGY_COST 25

class ClapTrap
{
protected:
	unsigned int		max_energy_points_;
	unsigned int		max_hit_points_;
	unsigned int		level_;
	unsigned int		melee_attack_damage_;
	unsigned int		ranged_attack_damage_;
	unsigned int		armor_damage_reduction_;
	std::string			name_;
	unsigned int		hit_points_;
	unsigned int		energy_points_;
public:
	void				setMaxEnergyPoints(int max_energy_points);
	int					getMaxEnergyPoints(void);

	void				setMaxHitPoints(int max_hit_points);
	int					getMaxHitPoints(void);

	void				setLevel(int level);
	int					getLevel(void);

	void				setMeleeAttackDamage(int melee_attack_damage);
	int					getMeleeAttackDamage(void);

	void				setRangeAttackDamage(int ranged_attack_damage);
	int					getRangeAttackDamage(void);

	void				setArmorDamageReduction(int armor_damage_reduction);
	int					getArmorDamageReduction(void);

	void				setName(int name);
	std::string			getName(void);

	void				setEnergyPoints(unsigned int energy_points);
	unsigned int		getEnergyPoints(void);

	void				setHitPoints(unsigned int hit_points);
	unsigned int		getHitPoints(void);

	void				rangedAttack(std::string const & target);
	void				meleeAttack(std::string const & target);
	void				takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);

	ClapTrap			&operator = (ClapTrap const & obj);
	ClapTrap(ClapTrap const & obj);
	ClapTrap(int max_energy_points, int max_hit_points,
			int level, int melee_attack_damage, int ranged_attack_damage,
			int armor_damage_reduction, std::string name,
			unsigned int hit_points, unsigned int energy_points);
	ClapTrap(void);
	~ClapTrap(void);
};

#endif
