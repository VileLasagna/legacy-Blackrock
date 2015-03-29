#include "BlackrockMainState.h"


BlackrockMainState::BlackrockMainState()
{
	self = 1;
	ret = self;
	SDLDisplay::instance()->setSize(1920,1200);
	SDLDisplay::instance()->FullScreen();
	BR = new Blackrock();
	BG = new SDLImage();
	FG = new SDLImage();
	LS = new LaserShooter();
	BG->Load("downtown-london2.jpg");
	FG->Load("FirstLevelTex.jpg");
	//FG->setColourKey();
	//BR->setPos(Vec2f(300,800));
	BR->live();
	SoundManager::instance()->loadMusic("bombedcity.mp3");
	SoundManager::instance()->setMusicLoop(-1);
	SoundManager::instance()->PlayMusic();
}

int BlackrockMainState::Update()
{
	EventHandler::Update();
	BR->Update();
	if(LS->WaveClear() && !(BR->isDead()))
	{
		LS->Fire();
	}
	LS->Update(BR);
//	BR->FGCollision(FG);
	return ret;
}

void BlackrockMainState::Draw()
{
	BG->Blit();
	FG->Blit(0,1047);
	BR->Draw();
	LS->Draw();
}


void BlackrockMainState::onKeyboardEvent(const SDL_KeyboardEvent &e)
{
	if (e.keysym.sym == SDLK_ESCAPE)
	{
		ret = -1;
	}
	if (e.keysym.sym == SDLK_RETURN && e.type == SDL_KEYDOWN && e.keysym.mod == KMOD_ALT)
	{
		SDLDisplay::instance()->ToggleFS();
	}
	if (e.keysym.sym == SDLK_RIGHT && e.type == SDL_KEYDOWN)
	{
		
		BR->walkRight();
	}
	if (e.keysym.sym == SDLK_RIGHT && e.type == SDL_KEYUP)
	{
		BR->stopWalk();
	}
	if (e.keysym.sym == SDLK_LEFT && e.type == SDL_KEYDOWN)
	{
		BR->walkLeft();
	}
	if (e.keysym.sym == SDLK_LEFT && e.type == SDL_KEYUP)
	{
		BR->stopWalk();
	}
	if (e.keysym.sym == SDLK_SPACE && e.type == SDL_KEYDOWN)
	{
		if(BR->isDead())
		{
			BR->live();
			LS->Reset();
		}
		else
		{
			BR->jump();
		}
	}
	if (e.keysym.sym == SDLK_a && e.type == SDL_KEYDOWN)
	{
		//BR->attack();
		//LS->Fire();
	}
	if (e.keysym.sym == SDLK_DOWN && e.type == SDL_KEYDOWN)
	{
		
		BR->crouch();
	}
	if (e.keysym.sym == SDLK_DOWN && e.type == SDL_KEYUP)
	{
		BR->stand();
	}

}

void BlackrockMainState::onJoyAxisEvent(const SDL_JoyAxisEvent &e)
{

}

void BlackrockMainState::onJoyHatEvent(const SDL_JoyHatEvent &e)
{

}

void BlackrockMainState::onJoyButtonEvent(const SDL_JoyButtonEvent &e)
{

}




