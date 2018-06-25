/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:39:26 by akokoshk          #+#    #+#             */
/*   Updated: 2018/06/12 22:07:15 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "tool.hpp"
#include <ctime>
#include "ftList.hpp"

#include "Boss.hpp"
#include "Asteroid.hpp"
#include "Player.hpp"
#include "Enemies.hpp"
#include <unistd.h>
#include "GameObj.hpp"
#include "Ncurse.hpp"

class Game
{
private:
	int		_score;
	time_t	_time;
	unsigned int _usleep;
	ftList	_objects;
	Player	*_player;

public:
	Game();
	Game(Game const &);
	~Game();
	Game &operator=(Game const &);

	void addObj(GameObj *);
	void rmObj(unsigned int idx);
	GameObj *getObj(unsigned int idx) const;
	void clearObjList();
	unsigned int getObjNum() const;

	void setScore(int);
	int getScore() const;
	std::string getScoreStr() const;
	time_t getTime() const;
	std::string getTimeStr() const;
	time_t getTimeDlt() const;
	ftList const & getObjectsList() const;

	void addPlayer();
	Player *getPlayer() const;

	bool checkAllCollision(GameObj *) const;
	bool checkThisPlace(t_xy) const;


	Player *gameStart(); //time counting
	void rmOffScreenObj();
	void rmDeadObj();


	void gameCoreLoop();


	void clearAllObj(Ncurse *ncur) const;
	void drawAllObj(Ncurse *ncur) const;

	//----------------------------------------------------------------

	void gameOver(Player *player, unsigned int distans);
	void enemiesShots();

	void addAsteroids(int);
    void addEnemies(int n);

	void spawnBoss(int n, Player *player);
};

#endif
