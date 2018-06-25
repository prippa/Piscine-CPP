/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemies.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:21:19 by akokoshk          #+#    #+#             */
/*   Updated: 2018/06/10 21:12:04 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemies.hpp"
#include "tool.hpp"
#include <iostream>

Enemies::Enemies():GameObj(WIDTH / 2, 0, o_enemy, c_enemy, 'W')
{
	_size = 1;
	_hp = 20;
}

Enemies::Enemies(t_xy pos, int hp, char c):GameObj(pos, o_enemy, c_enemy, c)
{
	_size = 1;
	_hp = (hp > 0) ? hp : 0;
}


Enemies& Enemies::operator=(Enemies const & src)
{
	setPosition(src.getPosition());
	setType(src.getType());
	setColor(src.getColor());
	setChar(src.getChar());
	_size = src.getSize();
	_hp = src.getHP();

	return (*this);
}

Enemies::Enemies(Enemies const & src)
{
	*this = src;
}

Enemies::~Enemies()
{
}

void Enemies::takeDamage(int dmg)
{
	if (dmg > 0 && _hp > 0)
		_hp -= dmg;
}

int Enemies::getHP() const
{
	return (_hp);
}

int Enemies::getSize() const
{
	return (_size);
}

void Enemies::defaultMovement(ftList *_objects)
{
	int rand_move = rand() % 3;

	if (rand_move == 0)
		moveDOWN(_objects);
	else if (rand_move == 1)
		moveLEFT(_objects);
	else if (rand_move == 2)
		moveRIGHT(_objects);
}

Shot* Enemies::makeShot()
{
	t_xy newPos = getPosition();
	if (++newPos.y <= HIGHT - 1)
		return (new Shot(newPos, d_down, o_obstacle, c_obstacle, '|'));
	return (NULL);
}
