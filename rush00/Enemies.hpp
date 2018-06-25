/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemies.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:21:28 by akokoshk          #+#    #+#             */
/*   Updated: 2018/06/07 20:23:32 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "GameObj.hpp"
#include "Shot.hpp"

class Enemies : public GameObj
{
private:
	int _size;

public:
	Enemies();
	Enemies(t_xy pos, int hp, char c);
	Enemies(Enemies const &);
	~Enemies();

	Enemies &operator= (Enemies const &);

	void	takeDamage(int n);
	int		getHP() const;
	int		getSize() const;

	Shot*	makeShot();

	virtual void defaultMovement(ftList *_objects);
};

#endif
