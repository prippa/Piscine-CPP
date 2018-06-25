#include "Asteroid.hpp"

Asteroid::Asteroid():GameObj(WIDTH / 2, 0, o_background, c_background, '.')
{
	_size = 1;
	_hp = 10;
	_flag = false;
}

Asteroid::Asteroid(t_xy pos, int hp, char c):GameObj(pos, o_background, c_background, c)
{
	_size = 1;
	_hp = (hp > 0) ? hp : 0;
	_flag = false;
}


Asteroid& Asteroid::operator=(Asteroid const & src)
{
	setPosition(src.getPosition());
	setType(src.getType());
	setColor(src.getColor());
	setChar(src.getChar());
	_size = src.getSize();
	_hp = src.getHP();
	_flag = false;

	return (*this);
}

Asteroid::Asteroid(Asteroid const & src)
{
	*this = src;
}

Asteroid::~Asteroid()
{
}

void Asteroid::takeDamage(int dmg)
{
	if (dmg > 0 && _hp > 0)
		_hp -= dmg;
}

int Asteroid::getHP() const
{
	return (_hp);
}

int Asteroid::getSize() const
{
	return (_size);
}

void Asteroid::defaultMovement(ftList *_objects)
{
	if (_flag)
	{
		moveDOWN(_objects);
		_flag = false;
	}
	else
		_flag = true;
}
