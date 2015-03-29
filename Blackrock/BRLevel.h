#ifndef BR_LEVEL_H
#define BR_LEVEL_H

#include "SDLImage.h"
#include "GameObject.h"
#include "Rect.h"
#include "Sprite.h"
#include <vector>

class BRLevel:public GameObject
{
public:

	BRLevel();
	void Update();
	void Draw();
	virtual const char* getType() const {return "BRLevel";}
	void loadTex(const char* filename);
	void collision(Sprite* S);

private:

	SDLImage tex;
	std::vector<Rectf> blocks;



};



#endif //BR_LEVEL_H