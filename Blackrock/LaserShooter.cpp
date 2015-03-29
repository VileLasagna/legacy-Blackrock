#include "LaserShooter.h"


LaserShooter::LaserShooter()
{
	clear = true;
	level = 1;
	lasfire = new SoundFX(SoundManager::instance()->loadSound("pcanonmet.wav"));

}

void LaserShooter::Reset()
{
	clear = true;
	level = 1;
	lasers.clear();
}

void LaserShooter::Fire()
{
	if(!clear)
	{
		return;
	}
	if (!lasfire)
	{
		lasfire = new SoundFX(SoundManager::instance()->loadSound("pcanonmet.wav"));
	}
	lasfire->setLoop(level-1);
	SoundManager::instance()->playSound(lasfire);
	clear = false;
	for(int i = 0; i <level; i++)
	{
		lasers.push_back(new Sprite("Laser.AnimSheet"));
		lasers[i]->setPos(Vec2f(1900 + (i*500) , 830 + 3*((rand()%100)-50) ));
		lasers[i]->setVel(Vec2f(-200 - (level*50) + ((rand()%100)-50) , 0));
	}

}

bool LaserShooter::Update(Blackrock *BR)
{
	int out = 0;
	for(unsigned int i = 0; i < lasers.size(); i++)
	{
		lasers[i]->playAnimation(1);
		if(!(BR->isDead()) && lasers[i]->pixCollision(*(BR->getSprite())) )
		{
			BR->die();
		}
		if(lasers[i]->getPos().X() < -50)
		{
			out++;
		}

	}
	if ( !clear && out >= lasers.size())
	{
		lasers.clear();
		clear = true;
		levelUp();
	}
	if(lasfire && lasfire->hasFinished())
	{
		delete lasfire;
		lasfire = 0;
	}
	return false;
}

void LaserShooter::Draw()
{
	for(unsigned int i = 0; i < lasers.size(); i++)
	{
		lasers[i]->Draw();
	}
}

void LaserShooter::setLevel(int i)
{
	level = i;
}

bool LaserShooter::WaveClear()
{
	return clear;
}