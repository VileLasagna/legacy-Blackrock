#ifndef BLACKROCK_H
#define BLACKROCK_H

#include "Sprite.h"
#include "SoundFX.h"
#include "SoundManager.h"
#include "GameObject.h"


class Blackrock : public GameObject
{
public:

	const Sprite* getSprite() const{return BR;}
	Blackrock();
	void jump();
	void fall();
	void walkRight();
	void walkLeft();
	void Update();
	void stopWalk();
	void land();
	void attack();
	void Draw();
	void crouch();
	void stand();
	const char* getType() const {return "BlackRock";}
	void setPos(const Vec2f& pos);
	Vec2f getVel() const {return BR->getVel();}
	bool isDead(){return dead;}
	void die();
	void live();
	//void FGCollision(SDLImage* FG);

private:

	Sprite* weapon;
	Sprite* BR;
	float jumpTimer;
	bool falling;
	bool right;
	int anim;
	int wAnim;
	bool attacking;
	bool crouched;
	SoundFX* atkfx;
	SoundFX* deathfx;
	bool dead;

};




#endif //BLACKROCK_H