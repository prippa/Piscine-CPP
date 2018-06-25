#ifndef BOSS_HPP
# define BOSS_HPP

#include "GameObj.hpp"
#include "Shot.hpp"

class Boss : public GameObj
{
private:
	int _size;
	int _move_flag;

public:
	Boss();
	Boss(t_xy pos, int hp, char c);
	Boss(Boss const &);
	~Boss();

	Boss &operator= (Boss const &);

	void	takeDamage(int n);
	int		getHP() const;
	int		getSize() const;

	Shot*	makeShot();

	virtual void defaultMovement(ftList *_objects);
};

#endif
