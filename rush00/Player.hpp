/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:28:10 by akokoshk          #+#    #+#             */
/*   Updated: 2018/06/12 22:35:55 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameObj.hpp"
#include "Shot.hpp"

class Player : public GameObj
{
private:
	int		_lives;

public:
	Player();
	Player(int hp, int lives);
	Player(t_xy pos, int hp, int lives);
	Player(Player const &);
	~Player();

	Player&	operator= (Player const &);

	int		getHP() const;
	int		getLivesNum() const;
	Shot*	makeShot(int type);

	GameObj* clone() const;

	void defaultMovement(ftList *_objects);
};

#endif
