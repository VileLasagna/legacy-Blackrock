#include "Blackrock.h"



Blackrock::Blackrock()
{
	std::string filename = "Soma.SheetList";
	weapon = 0;
	jumpTimer = 0;
	falling = 0;
	right = true;
	BR = new Sprite("Soma.Sheetlist");
	anim = 1;
	weapon = new Sprite("Guitar.AnimSheet");
	attacking = false;
	wAnim = 3;
	atkfx = 0;
	crouched = false;
	dead = false;
	deathfx = new SoundFX(SoundManager::instance()->loadSound("Death.wav"));
}

void Blackrock::Draw()
{
	weapon->Draw();
	BR->Draw();
}

void Blackrock::Update()
{
	if(!dead)
		{
		if (jumpTimer > 0)
		{
			jumpTimer -= SDLDisplay::instance()->getDtSecs();
			if (jumpTimer < 0)
			{
				fall();
			}
		}
		if (falling)
		{
			if (BR->getPos().Y() >= 800)
			{
				setPos(Vec2f(BR->getPos().X(),800));
				land();
			}
		}
		if(anim == 30 || anim == 90)
		{
			if (BR->getAnimation().Y() == 12)
			{
				attacking = false;
				wAnim = 3;
			}
		}
		
		if( BR->getPos().X() < -20 )
		{
			BR->setPos(Vec2f(-20,BR->getPos().Y()));
			BR->setVel(Vec2f(0,BR->getVel().Y()));
		}
		else
		{
			if( BR->getPos().X() > 1770 )
			{
				BR->setPos(Vec2f(1770,BR->getPos().Y()));
				BR->setVel(Vec2f(0,BR->getVel().Y()));
			}
		}
	}

	anim = BR->playAnimation(anim);
	wAnim = weapon->playAnimation(wAnim);
	if (atkfx && atkfx->hasFinished())
	{
		delete atkfx;
		atkfx = 0;
	}
	if (deathfx && deathfx->hasFinished())
	{
		delete deathfx;
		deathfx = 0;
	}
}

void Blackrock::setPos(const Vec2f& pos)
{
	BR->setPos(pos);
}

void Blackrock::fall()
{
	BR->setVel(Vec2f(BR->getVel().X(),450));
	jumpTimer = 0;
	falling = true;
}

void Blackrock::die()
{
	BR->setVel(Vec2f(-30,0));
	anim = 58;
	dead = true;
	if(!deathfx)
	{
		deathfx = new SoundFX(SoundManager::instance()->loadSound("Death.wav"));
	}
	SoundManager::instance()->playSound(deathfx);

}

void Blackrock::live()
{
	dead = false;
	BR->setVel(Vec2f(0,0));
	BR->setPos(Vec2f(100,500));
	anim = 10;
	fall();
}

void Blackrock::jump()
{
	if(dead){return;}

	if (jumpTimer)
	{//doubleJump goes here
		return;
	}
	if (falling)
	{
		return;
	}
	BR->setVel(Vec2f(BR->getVel().X(),-450));
	if (right)
	{
		anim = 8;
	}
	else
	{
		anim = 68;
	}
	jumpTimer = 0.6f;
}
void Blackrock::walkLeft()
{
	if(dead){return;}

	if (attacking) {return;}
	if (crouched) {anim = 72; right = false; return;}
	BR->setVel(Vec2f(-350,BR->getVel().Y()));
	if (!falling)
	{
		anim = 62;
	}
	right = false;
}

void Blackrock::walkRight()
{
	if(dead){return;}

	if (attacking) {return;}
	if (crouched) {anim = 12; right = true; return;}
	BR->setVel(Vec2f(350,BR->getVel().Y()));
	if (!falling)
	{
		anim = 2;
	}
	right = true;
}

void Blackrock::stopWalk()
{
	if(dead){return;}

	if (crouched) {return;}
	BR->setVel(Vec2f(0,BR->getVel().Y()));
	if (!falling)
	{
		if(right)
		{
			anim = 4;
		}
		else
		{
			anim = 64;
		}
	}
}

void Blackrock::land()
{
	if(dead){return;}

	BR->setVel(Vec2f(BR->getVel().X(),0));
	if(BR->getVel().X() != 0)
	{
		if(right)
		{
			anim = 2;
		}
		else
		{
			anim = 62;
		}
	}
	else
	{
		if(right)
		{
			anim = 1;
		}
		else
		{
			anim = 61;
		}
	}
	falling = false;
}

void Blackrock::attack()
{
	if(dead){return;}

	if(attacking|| falling || crouched)
	{return;}
	BR->setVel(Vec2f()); //0,0
	attacking = true;
	weapon->setPos(BR->getPos());
	if (right)
	{
		wAnim = 1;
	}
	else
	{
		wAnim = 2;
	}
	if (right)
	{
		anim = 30;
	}
	else
	{
		anim = 90;
	}
	atkfx = new SoundFX(SoundManager::instance()->loadSound("attack3.wav"));
	SoundManager::instance()->playSound(atkfx);
}

void Blackrock::crouch()
{
	if(dead){return;}

	if (jumpTimer || falling || crouched)
	{
		return;
	}
	BR->setVel(Vec2f(0,BR->getVel().Y()));
	if (right)
	{
		anim = 11;
	}
	else
	{
		anim = 71;
	}
	crouched = true;
}

void Blackrock::stand()
{
	if(dead || (!crouched) ){return;}

	if (anim == 11 || anim == 12)
	{
		anim = 13;
	}
	if (anim == 71 || anim == 72)
	{
		anim = 73;
	}
	crouched = false;
}
