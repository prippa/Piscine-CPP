/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.cpp                                        :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:21:19 by akokoshk          #+#    #+#             */
/*   Updated: 2018/06/10 21:12:04 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Boss.hpp"
#include "tool.hpp"
#include <iostream>

Boss::Boss():GameObj(WIDTH / 2, 0, o_boss, c_boss, 'V')
{
	_size = 1;
	_hp = 50;
	_move_flag = 5;
}

Boss::Boss(t_xy pos, int hp, char c):GameObj(pos, o_boss, c_boss, c)
{
	_size = 1;
	_hp = (hp > 0) ? hp : 0;
	_move_flag = 5;
}


Boss& Boss::operator=(Boss const & src)
{
	setPosition(src.getPosition());
	setType(src.getType());
	setColor(src.getColor());
	setChar(src.getChar());
	_size = src.getSize();
	_hp = src.getHP();
	_move_flag = 5;

	return (*this);
}

Boss::Boss(Boss const & src)
{
	*this = src;
}

Boss::~Boss()
{
}

void Boss::takeDamage(int dmg)
{
	if (dmg > 0 && _hp > 0)
		_hp -= dmg;
}

int Boss::getHP() const
{
	return (_hp);
}

int Boss::getSize() const
{
	return (_size);
}

void Boss::defaultMovement(ftList *_objects)
{
	if (_move_flag == 0)
	{
		moveDOWN(_objects);
		_move_flag = 5;
	}
	_move_flag--;
}

Shot* Boss::makeShot()
{
	t_xy newPos = getPosition();
	if (++newPos.y <= HIGHT - 1)
		return (new Shot(newPos, d_down, o_obstacle, c_obstacle, '|'));
	return (NULL);
}
