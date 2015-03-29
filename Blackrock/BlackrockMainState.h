#ifndef BLACKROCKMAIN_H
#define BLACKROCKMAIN_H



#include "Sprite.h"
#include "SDLImage.h"
#include "EventHandler.h"
#include "GameState.h"
#include "Blackrock.h"
#include "LaserShooter.h"
#include <Vector>

class BlackrockMainState: public GameState
{
public:
	BlackrockMainState();
	int Update();
	void Draw();

private:

	void BRFGCollision();

	SDLImage* BG;
	SDLImage* FG;
	void onKeyboardEvent(const SDL_KeyboardEvent& e);
	void onJoyAxisEvent(const SDL_JoyAxisEvent& e);
	void onJoyHatEvent(const SDL_JoyHatEvent& e);
	void onJoyButtonEvent(const SDL_JoyButtonEvent& e);
	Blackrock* BR;
	LaserShooter* LS;
	//std::vector<Sprite*> enemies;
};


#endif //BLACKROCKMAIN_H