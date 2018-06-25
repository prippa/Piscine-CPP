/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurse.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:13:22 by akokoshk          #+#    #+#             */
/*   Updated: 2018/06/12 20:51:14 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef NCURSE_HPP
#define NCURSE_HPP

#include "tool.hpp"
#include <ncurses.h>
#include <iostream>

class Ncurse
{
private:
	WINDOW	*_win;

public:
	Ncurse();
	Ncurse(Ncurse const &);
	~Ncurse();
	Ncurse &operator=(Ncurse const &);

	WINDOW *getWin() const;
	void setWin(WINDOW *);
	void n_setWinColor(t_colrpair);
	void n_setOuterWinColor(t_colrpair);

	void n_drawFrame();
	void n_drawStatusBar(std::string score, std::string time, std::string helth, std::string distance, std::string _usleep);

	void n_intColor();

	void n_refreshAll();
	void n_refreshWindow();

	void n_print(t_xy, char, t_colrpair);
};

#endif
