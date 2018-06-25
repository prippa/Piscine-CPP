#ifndef ASTEROID_HPP
# define ASTEROID_HPP

#include "GameObj.hpp"
#include <iostream>

class Asteroid : public GameObj
{
private:
	int _size;
	bool _flag;

public:
	Asteroid();
	Asteroid(t_xy pos, int hp, char c);
	Asteroid(Asteroid const &);
	~Asteroid();

	Asteroid &operator= (Asteroid const &);

	void	takeDamage(int n);
	int		getHP() const;
	int		getSize() const;

	void	shoot();

	virtual void defaultMovement(ftList *_objects);
};

#endif
