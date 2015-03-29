#ifndef ENEMY_H
#define ENEMY_H


#include "Sprite.h"


class Enemy: public Sprite
{

public:
	Enemy();
	void attack();
	void die();
	void forward();
private:
	bool attacking, dead;
	int anim;
};

#endif