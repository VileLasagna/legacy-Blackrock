#include <SDL.h>
#include <assert.h>
#include "Game.h"
#include "BlackrockMainState.h"
#include "BRSplashState.h"
#include <stdio.h>
#include <fstream>

int main(int, char**)
{

	Game::instance() -> addState (new BRSplashState() );
	Game::instance() -> addState (new BlackrockMainState());
	//Game::instance() -> showFPS();
	Game::instance() -> Run();
	Game::Clear();
    return 0;
}