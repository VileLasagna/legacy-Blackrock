#include "BRSplashState.h"

BRSplashState::BRSplashState()
{
	self = 0;
	ret = self;
	FG.Load("BR-Splash.jpg");
}

void BRSplashState::Draw()
{
	FG.Blit();
}

int BRSplashState::Update()
{
	EventHandler::Update();
	return ret;
}

void BRSplashState::onKeyboardEvent( const SDL_KeyboardEvent& e)
{
	if (e.type == SDL_KEYDOWN)
	{
		ret = 1;
	}
}