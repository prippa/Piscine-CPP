/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shot.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 21:15:53 by akokoshk          #+#    #+#             */
/*   Updated: 2018/06/12 22:37:35 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shot.hpp"

Shot::Shot():GameObj(0, 0, o_projectile, c_projectile, '*')
{
	_dir = d_up;
}

Shot::Shot(t_xy pos, t_direction dir, t_type type, t_colrpair colp, char c):GameObj(pos, type, colp, c)
{
	_dir = dir;
}

Shot::~Shot()
{
}

Shot& Shot::operator=(Shot const & src)
{
	setPosition(src.getPosition());
	setType(src.getType());
	setColor(src.getColor());
	setChar(src.getChar());
	_dir = src.getDir();

	return (*this);
}

Shot::Shot(Shot const & src)
{
	*this = src;
}

t_direction Shot::getDir() const
{
	return (_dir);
}

void Shot::setDir(t_direction d)
{
	_dir = d;
}

void Shot::defaultMovement(ftList *_objects)
{
	if (_dir == d_up)
		moveUP(_objects);
	else if (_dir == d_down)
	{
		moveDOWN(_objects);
		moveDOWN(_objects);
	}
}
