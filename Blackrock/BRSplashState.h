#include "GameState.h"
#include "SDLImage.h"


class BRSplashState:public GameState
{
public:

	BRSplashState();
	int Update();
	void Draw();

private:

	void onKeyboardEvent(const SDL_KeyboardEvent& e);
	SDLImage FG;
};