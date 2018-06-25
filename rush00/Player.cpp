/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:28:04 by akokoshk          #+#    #+#             */
/*   Updated: 2018/06/12 22:36:54 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "tool.hpp"
#include "Player.hpp"

Player::Player() : GameObj(WIDTH / 2, HIGHT - 1, o_player, c_player, 'A')
{

}

Player::Player(Player const & src)
{
	*this = src;
}

Player::Player(int hp, int lives):GameObj(WIDTH / 2, HIGHT - 1, o_player, c_player, 'A')
{

	_lives = (lives > 0) ? lives : 0;
	_hp = (hp > 0) ? hp : 0;
}

Player::Player(t_xy pos, int hp, int lives):GameObj(pos, o_player, c_player, 'A')
{
	_lives = (lives > 0) ? lives : 0;
	_hp = (hp > 0) ? hp : 0;
}

Player& Player::operator=(Player const & src)
{
	setPosition(src.getPosition());
	setType(src.getType());
	setColor(src.getColor());
	setChar(src.getChar());
	_lives = src.getLivesNum();
	_hp = src.getHP();

	return (*this);
}

Player::~Player()
{
}

int Player::getHP() const
{
	return (_hp);
}

int Player::getLivesNum() const
{
	return (_lives);
}

Shot* Player::makeShot(int type)
{
	t_xy newPos = getPosition();
	if (type == 1 && (newPos.y -= 2) >= 0)
		return (new Shot(newPos, d_up, o_projectile, c_projectile, '^'));
	else if (type == 2 && (newPos.y -= 1) >= 0 && (newPos.x -= 1) >= 0)
		return (new Shot(newPos, d_up, o_projectile, c_projectile, '^'));
	else if (type == 3 && (newPos.y -= 1) >= 0 && (newPos.x += 1) <= (WIDTH - 1))
		return (new Shot(newPos, d_up, o_projectile, c_projectile, '^'));
	return (NULL);
}

GameObj* Player::clone() const
{
	return (new Player(*this));
}

void Player::defaultMovement(ftList *_objects)
{
	_objects = NULL;
}
