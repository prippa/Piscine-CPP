/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGameObj.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 20:12:19 by akokoshk          #+#    #+#             */
/*   Updated: 2018/06/09 18:59:31 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGAMEOBJ_HPP
#define IGAMEOBJ_HPP

#include "tool.hpp"
#include "ftList.hpp"

class GameObj;

class IGameObj
{
public:
	virtual ~IGameObj() {};
	virtual bool getIntersection(GameObj *) const = 0;
	virtual t_xy getPosition() const = 0;
	virtual void setPosition(int x, int y) = 0;

	virtual void moveUP(ftList *_objects) = 0;
	virtual void moveDOWN(ftList *_objects) = 0;
	virtual void moveLEFT(ftList *_objects) = 0;
	virtual void moveRIGHT(ftList *_objects) = 0;
};

#endif
