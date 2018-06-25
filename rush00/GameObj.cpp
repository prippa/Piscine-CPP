/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObj.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 20:27:13 by akokoshk          #+#    #+#             */
/*   Updated: 2018/06/12 22:37:12 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "GameObj.hpp"

GameObj::GameObj()
{
	setPosition(0, 0);
	_type = o_background;
	_color = c_background;
	_speed = 1;
	_hp = 10;
}

GameObj::GameObj(int x, int y, t_type type, t_colrpair colr, char c)
{
	setPosition(x, y);
	_type = type;
	_color = colr;
	_c = c;
	_speed = 1;
	_hp = 10;
}

GameObj::GameObj(t_xy pos, t_type type, t_colrpair colr, char c)
{
	setPosition(pos);
	_type = type;
	_color = colr;
	_c = c;
	_speed = 1;
	_hp = 10;
}

GameObj::~GameObj()
{
}

GameObj& GameObj::operator=(GameObj const & src)
{
	_position = src.getPosition();
	_type = src.getType();
	_color = src.getColor();
	_c = src.getChar();
	_speed = src.getSpeed();
	_hp = src.getHP();
	return (*this);
}

GameObj::GameObj(GameObj const & src)
{
	*this = src;
}

bool GameObj::getIntersection(GameObj *trg) const
{
	if (trg != NULL)
	{
		if(this == trg) //колизия сам с собой
			return (false);
		t_xy trg_pos = trg->getPosition();
		if (_position.x == trg_pos.x && _position.y == trg_pos.y)
			return (true);
	}
	return (false);
}

bool GameObj::getIntersection(t_xy pos) const
{
	if (_position.x == pos.x && _position.y == pos.y)
		return (true);
	return (false);
}


void GameObj::takeDamage(int dmg)
{
	if (dmg > 0 && _hp > 0)
		_hp -= dmg;
}

void GameObj::makeCollision(ftList *_objects)
{
	GameObj *trg = NULL;

	unsigned int num = _objects->getObjNum();

	for(unsigned int i = 0; i < num; i++)
	{
		trg = (GameObj*)_objects->getObj(i);

		if(this == trg) //колизия сам с собой
			continue;
		if (_type == o_background || trg->getType() == o_background)
			continue;
		if (_type == o_enemy && trg->getType() == o_enemy)
			continue;
		if (_type == o_enemy && trg->getType() == o_boss)
			continue;
		if (_type == o_boss && trg->getType() == o_enemy)
			continue;
		//enemy
		if (_type == o_obstacle && trg->getType() == o_enemy)
			continue;
		if (_type == o_enemy && trg->getType() == o_obstacle)
			continue;
		//boss
		if (_type == o_obstacle && trg->getType() == o_boss)
			continue;
		if (_type == o_boss && trg->getType() == o_obstacle)
			continue;
		if (_hp <= 0 || trg->getHP() <= 0)
			continue;

		if (getIntersection(trg))
		{
			int myhp = _hp;
			takeDamage(trg->getHP());
			trg->takeDamage(myhp);
		}
	}
}



//*****************MOVEMENT
void GameObj::defaultMovement(ftList *_objects)
{
	moveDOWN(_objects);
}

void GameObj::moveUP(ftList	*_objects)
{
	if (_position.y > 0)
		_position.y--;
	makeCollision(_objects);
}

void GameObj::moveDOWN(ftList *_objects)
{
	if (_position.y < HIGHT - 1)
		_position.y++;
	makeCollision(_objects);
}

void GameObj::moveLEFT(ftList *_objects)
{
	if (_position.x > 0)
		_position.x--;
	makeCollision(_objects);
}

void GameObj::moveRIGHT(ftList *_objects)
{
	if (_position.x < WIDTH - 1)
		_position.x++;
	makeCollision(_objects);
}



//*****************GETTER SETTER
void GameObj::setPosition(t_xy pos)
{
	_position = pos;
}

void GameObj::setType(t_type type)
{
	_type = type;
}

void GameObj::setColor(t_colrpair colr)
{
	_color = colr;
}

char GameObj::getChar() const
{
	return (_c);
}

void GameObj::setChar(char c)
{
	_c = c;
}

int GameObj::getSpeed() const
{
	return (_speed);
}

void GameObj::setSpeed(int spd)
{
	_speed = spd;
}

int GameObj::getHP() const
{
	return _hp;
}

void GameObj::setHP(int hp)
{
	_hp = hp;
}

void GameObj::setPosition(int x, int y)
{
	_position.x = x;
	_position.y = y;
}

t_type GameObj::getType() const
{
	return (_type);
}

t_colrpair GameObj::getColor() const
{
	return (_color);
}

t_xy GameObj::getPosition() const
{
	return (_position);
}












