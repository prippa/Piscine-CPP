/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObj.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 20:27:20 by akokoshk          #+#    #+#             */
/*   Updated: 2018/06/12 22:38:56 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEOBJ_HPP
#define GAMEOBJ_HPP

#include "IGameObj.hpp"

class GameObj : public IGameObj
{
private:
	t_xy		_position;
	t_type		_type;
	t_colrpair	_color;
	char 		_c;
	int			_speed;

protected:
	int _hp;

public:
	GameObj();
	GameObj(int, int, t_type, t_colrpair, char);
	GameObj(t_xy, t_type, t_colrpair, char);
	GameObj(GameObj const &);
	~GameObj();
	GameObj&	operator= (GameObj const &);

	bool		getIntersection(GameObj *) const;
	bool		getIntersection(t_xy) const;
	t_xy		getPosition() const;
	t_type		getType() const;
	t_colrpair	getColor() const;
	char		getChar() const;
	int			getSpeed() const;

	void		setPosition(int x, int y);
	void		setPosition(t_xy);
	void		setType(t_type);
	void		setChar(char);
	void		setSpeed(int);
	void		setColor(t_colrpair);
	void		moveUP(ftList *_objects);
	void		moveDOWN(ftList	*_objects);
	void		moveLEFT(ftList	*_objects);
	void		moveRIGHT(ftList *_objects);

	virtual GameObj* clone() const;
	virtual void defaultMovement(ftList	*_objects);

	virtual int getHP() const;
	virtual void setHP(int);

	void 		makeCollision(ftList *_objects);
	void		takeDamage(int n);
};

#endif
