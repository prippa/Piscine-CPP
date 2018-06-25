/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 20:39:17 by akokoshk          #+#    #+#             */
/*   Updated: 2018/06/12 21:53:36 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game()
{
    srand (time(0));
	_score = 0;
	_time = 0;
	_player = NULL;
}

Game& Game::operator=(Game const & src)
{
	_score = src.getScore();
	_time = src.getTime();
	_player = (Player*)src.getPlayer()->clone();

	unsigned int num = src.getObjNum();
	for(unsigned int i = 0; i < num; i++)
		addObj(src.getObj(i)->clone());

	return (*this);
}

Game::Game(Game const & src)
{
	*this = src;
}

Game::~Game()
{
	clearObjList();
}

GameObj* Game::getObj(unsigned int idx) const
{
	return ((GameObj*)_objects.getObj(idx));
}

void Game::addObj(GameObj *obj)
{
	if (obj != NULL)
	{
		if (!checkAllCollision(obj))
			_objects.addObj((void *) obj);
		else
			delete (obj);
	}
}

void Game::rmObj(unsigned int idx)
{
	GameObj *obj = getObj(idx);
	if (obj != NULL)
	{
		delete (obj);
		_objects.rmObjFromList(idx);
	}
}

void Game::clearObjList()
{
	for(unsigned int i = 0; i < _objects.getObjNum(); i++)
	{
		rmObj(i);
		i = 0;
	}
	_objects.clearList();
}

int Game::getScore() const
{
	return (_score);
}

unsigned int Game::getObjNum() const
{
	return (_objects.getObjNum());
}

ftList const & Game::getObjectsList() const
{
	return (_objects);
}

time_t Game::getTime() const
{
	return (_time);
}

time_t Game::getTimeDlt() const
{
	time_t t = time(0);
	t = t - _time;
	return (t);
}

std::string Game::getTimeStr() const
{
	time_t t = getTimeDlt();
	tm *dateTimeNow = gmtime(&t);
	char buf[80];
	strftime (buf, 80, "%H:%M:%S", dateTimeNow); //"%Y%m%d_%H%M%S"
	return (std::string(buf));
}

void Game::setScore(int s)
{
	_score = s;
}

GameObj* GameObj::clone() const
{
	return (new GameObj(*this));
}

Player* Game::getPlayer() const
{
	return (_player);
}

std::string Game::getScoreStr() const
{
	return (std::to_string(_score));
}

void Game::addPlayer()
{
	if (_player == NULL)
	{
		t_xy pos;
		pos.x = WIDTH / 2;
		pos.y = HIGHT - 1;
		_player = new Player(pos, 100, 2);
		addObj((GameObj*)_player);
	}
}

Player* Game::gameStart()
{
	_time = time(0);
	_score = 0;
	addPlayer();

	return (_player);
}

bool Game::checkAllCollision(GameObj *obj) const
{
	unsigned int num = getObjNum();
	if(num > 0)
		for(unsigned int i = 0; i < num; i++)
			if (getObj(i)->getIntersection(obj))
				return (true);
	return (false);
}

bool Game::checkThisPlace(t_xy pos) const
{
	unsigned int num = getObjNum();
	if(num > 0)
		for(unsigned int i = 0; i < num; i++)
			if (getObj(i)->getIntersection(pos))
				return (true);
	return (false);
}


//в ф-и проверки всего поля или интерсекшинов, после колизий хода, проверить жив ли игрок,
// если нет уменьшить к-во континиусов или удалить игрока, закончить игру
////////////////////////////////////////////////////////////////////////////////////////////
void Game::addAsteroids(int n)
{
    t_xy pos;

    pos.y = 0;
    for(int i = 0; i < n; i++)
    {
        pos.x = rand() % WIDTH;
		if (!checkThisPlace(pos))
		{
			int random_elm = rand() % 2;
			if (random_elm == 1)
				addObj(new Asteroid(pos, 10, '.'));
			else if (random_elm == 0)
				addObj(new Asteroid(pos, 10, '*'));
		}
    }
}

void Game::addEnemies(int n)
{
    t_xy pos;

    pos.y = 0;
    for(int i = 0; i < n; i++)
    {
        pos.x = rand() % WIDTH;
		if (!checkThisPlace(pos))
			addObj(new Enemies(pos, 10, 'W'));
    }
}

void Game::spawnBoss(int n, Player *player)
{
	t_xy pos = player->getPosition();
	t_xy tmp;

	pos.y = (n / 2);
	tmp.y = pos.y;
    for(int i = 1; i <= n; i += 2)
    {
		tmp.x = pos.x;
		tmp.y = pos.y;
		for (int j = 0; j < i; ++j)
		{
			if (!checkThisPlace(tmp))
				addObj(new Boss(tmp, 50, 'V'));
			tmp.x += 1;
		}
		pos.y -= 1;
		pos.x -= 1;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
void Game::enemiesShots()
{
	GameObj *obj = NULL;

	for (unsigned int i = 0; i < getObjNum(); ++i)
	{
		obj = getObj(i);
		if (obj->getType() == o_enemy && (rand() % 50) == 1)
		{
			addObj(((Enemies*)obj)->makeShot());
		}
		else if (obj->getType() == o_boss && (rand() % 7) == 1)
		{
			addObj(((Boss*)obj)->makeShot());
		}
	}
}

void Game::rmOffScreenObj()
{
	GameObj* obj = NULL;

	if(getObjNum() > 0)
		for(unsigned int i = 0; i < getObjNum(); i++)
		{
			obj = getObj(i);
			if ((obj->getType() == o_enemy
				 || obj->getType() == o_background
				 || obj->getType() == o_boss
				 || obj->getType() == o_obstacle)
				&& obj->getPosition().y == HIGHT - 1)
			{
				rmObj(i);
				i = 0;
			}
			else if (obj->getType() == o_projectile && obj->getPosition().y == 0)
			{
				rmObj(i);
				i = 0;
			}
		}
}

void Game::rmDeadObj()
{
	GameObj *obj = NULL;
	if(getObjNum() > 0)
		for(unsigned int i = 0; i < getObjNum(); i++)
		{
			obj = getObj(i);
			if (obj->getHP() <= 0)
			{
				if (obj->getType() == o_enemy)
					_score += 200;
				else if (obj->getType() == o_boss)
					_score += 1000;
				else if (obj->getType() == o_obstacle)
					_score += 10;
				rmObj(i);
				i = 0;
			}
		}
}


void Game::drawAllObj(Ncurse *ncur) const
{
	GameObj *obj = NULL;
	unsigned int num = getObjNum();
	if(num > 0)
		for(unsigned int i = 0; i < num; i++)
		{
			obj = getObj(i);
			t_xy pos = obj->getPosition();
			ncur->n_print(pos, obj->getChar(), obj->getColor());
		}
}

void Game::clearAllObj(Ncurse *ncur) const
{
	unsigned int num = getObjNum();
	if(num > 0)
		for(unsigned int i = 0; i < num; i++)
		{
			t_xy pos = getObj(i)->getPosition();
			ncur->n_print(pos, ' ', c_fade);
		}
}

void Game::gameOver(Player *player, unsigned int distans)
{
	t_xy pos = player->getPosition();
	int esc;

	sleep(1);
	clear();
	mvprintw(pos.y, pos.x, "GAME OVER\n");
	mvprintw(pos.y + 1, pos.x, "Your score: %d", _score);
	mvprintw(pos.y + 2, pos.x, "Your distans: %u", distans);
	mvprintw(pos.y + 4, pos.x, "Press ESC to quit");
	refresh();
	
	// Press ESC to quit
	esc = 0;
	while (esc != k_esc)
		esc = getch();
}

void Game::gameCoreLoop()
{
	Ncurse ncurs;

	ncurs.n_setWinColor(c_obstacle);

	Player *player = gameStart(); //старт игры


	int key = -1;
	int esc = -1;
	unsigned long tik = 0;
	_usleep = 30000;
	while (key != k_esc)
	{
		ncurs.n_drawStatusBar(getScoreStr(), getTimeStr(), std::to_string(player->getHP()), std::to_string(tik / 10), std::to_string(_usleep)); //******************

		// сначала очистка,
		// потом просчет движения/колизий,
		// потом отрисовка
		clearAllObj(&ncurs);

		//удаляем объекты которые вышли за край экрана
		rmOffScreenObj();


////******************************************
		unsigned int num = getObjNum();
		GameObj *obj = NULL;
		if(num > 0)
		{
			for(unsigned int j = 0; j < num; j++)
			{
				obj = getObj(j);
				if (obj->getType() != o_enemy && obj->getType() != o_boss)
					obj->defaultMovement(&_objects);
			}
			for(unsigned int j = 0; j < num; j++)
			{
				obj = getObj(j);
				if (obj->getType() == o_enemy || obj->getType() == o_boss)
					obj->defaultMovement(&_objects);
			}
		}
////******************************************

		timeout(0);
		key = getch();
		switch (key)
		{
			case k_space:
			{
				addObj(player->makeShot(1));
				addObj(player->makeShot(2));
				addObj(player->makeShot(3));
				break;
			}
			case k_up:
			{
				player->moveUP(&_objects);
				break;
			}
			case k_down:
			{
				player->moveDOWN(&_objects);
				break;
			}
			case k_left:
			{
				player->moveLEFT(&_objects);
				break;
			}
			case k_right:
			{
				player->moveRIGHT(&_objects);
				break;
			}
			case 'q':
			{
				_usleep += 10000;
				break;
			}
			case 'w':
			{
				if (_usleep != 0)
					_usleep -= 10000;
				break;
			}
			case 'e':
			{
				player->setHP(1000);
				break;
			}
		}

		//от залипани кнопок
		while ((esc = getch()) > -1 && esc != k_esc && esc != k_space);
		
		//player`s death
		if (_player->getHP() <= 0)
		{
			gameOver(player, tik / 10);
			break;
		}
		if (esc == k_esc)
			break;
		else if (esc == k_space)
		{
			addObj(player->makeShot(1));
			addObj(player->makeShot(2));
			addObj(player->makeShot(3));
		}

		enemiesShots();
		if (tik % 400 == 0)
			spawnBoss(15, player);
		if(tik % 10 == 0)
			addEnemies(2);
		if(tik % 3 == 0)
			addAsteroids(3);

		//удаляем мертвые/убитые объекты
		rmDeadObj();



		drawAllObj(&ncurs);

		ncurs.n_refreshWindow();
		tik++;


		usleep(_usleep);
	}
}














