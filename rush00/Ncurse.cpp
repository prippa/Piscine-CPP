/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurse.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:14:04 by akokoshk          #+#    #+#             */
/*   Updated: 2018/06/12 22:44:57 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ncurse.hpp"

Ncurse::Ncurse()
{
	initscr(); //initializes the terminal in curses mode
	noecho(); //These functions switches off echoing of characters typed by the user to the terminal
	keypad(stdscr, TRUE); //enables the reading of function keys like F1, F2, arrow keys etc.
	curs_set(0);
	_win = newwin(HIGHT, WIDTH, 2, 1);
	nodelay(_win, TRUE); //FALSE
	start_color();
	n_intColor();
	n_drawFrame();
	n_refreshAll();
}

Ncurse::~Ncurse()
{
	endwin();
	exit(0);
}

Ncurse& Ncurse::operator=(Ncurse const & src)
{
	setWin(src.getWin());
	return (*this);
}

Ncurse::Ncurse(Ncurse const  & src)
{
	*this = src;
}

WINDOW* Ncurse::getWin() const
{
	return (_win);
}

void Ncurse::setWin(WINDOW *w)
{
	_win = w;
}

void Ncurse::n_drawFrame()
{
	n_setOuterWinColor(c_border);
	for(int i = 0; i < SCREEN_WIDTH; i++)
	{
		mvaddch(0, i, '_');
		mvaddch(SCREEN_HIGHT - 1, i, '_');
	}

	for(int i = 1; i < SCREEN_HIGHT; i++)
	{
		mvaddch(i, 0, '|');
		mvaddch(i, SCREEN_WIDTH - 1, '|');
	}
}

void Ncurse::n_intColor()
{
	init_color(COLOR_WHITE, 600, 600, 600);
	init_pair(c_fade,  COLOR_BLACK,   COLOR_BLACK);
	init_pair(c_background,  COLOR_MAGENTA,   COLOR_BLACK); // ****color first player
	init_pair(c_player,  COLOR_GREEN,   COLOR_BLACK); // ****color first player
	init_pair(c_obstacle,  COLOR_YELLOW,   COLOR_BLACK); // ****color first player
	init_pair(c_enemy,  COLOR_CYAN,   COLOR_BLACK); // ****color first player
	init_pair(c_boss,  COLOR_BLUE,   COLOR_BLACK); // ****color first player
	init_pair(c_projectile,  COLOR_RED,   COLOR_BLACK); // ****color first player
	init_pair(c_border,  COLOR_WHITE,   COLOR_WHITE); // ****color first player
}

void Ncurse::n_refreshAll()
{
	wrefresh(_win);
	refresh(); /* Print it on to the real screen */
}

void Ncurse::n_refreshWindow()
{
	wrefresh(_win);
}


void Ncurse::n_drawStatusBar(std::string score, std::string time, std::string helth, std::string distance, std::string _usleep)
{
	n_setOuterWinColor(c_fade);
	mvprintw(1, WIDTH / 3, "                                                                 ");
	n_setOuterWinColor(c_obstacle);
	std::string sc = (!score.empty()) ? score : "0";
	std::string tm = (!time.empty()) ? time : "0";
	std::string out = ">> score:\t" + score + " | distance:\t" + distance + " | time:\t" + time + " | usleep:\t" + _usleep + " | HP:\t" + helth + " <<";
	mvprintw(1, WIDTH / 5, &out[0]);
}

void Ncurse::n_setWinColor(t_colrpair color)
{
	wattron(_win, COLOR_PAIR(color));
}

void Ncurse::n_setOuterWinColor(t_colrpair color)
{
	attron(COLOR_PAIR(color));
}


void Ncurse::n_print(t_xy pos, char c, t_colrpair clr)
{
	n_setWinColor(clr);
	mvwprintw(_win, pos.y, pos.x, "%c", c);
}
