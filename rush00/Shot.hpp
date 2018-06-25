/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shot.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 21:14:15 by akokoshk          #+#    #+#             */
/*   Updated: 2018/06/12 22:35:55 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOT_HPP
#define SHOT_HPP

#include "GameObj.hpp"

class Shot : public GameObj
{
private:
	t_direction	_dir;

public:
	Shot();
	Shot(t_xy pos, t_direction dir, t_type type, t_colrpair colp, char c);
	~Shot();
	Shot(Shot const &);
	Shot &operator=(Shot const &);

	t_direction		getDir() const;
	void			setDir(t_direction);

	virtual void	defaultMovement(ftList *_objects);
};

#endif
