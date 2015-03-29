
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "FileManager.h"
#include "ManagedFile.h"

class GameObject

{
public:

	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual ~GameObject(){};
	virtual bool Load(ManagedFile* F) {return true;}
	virtual const char* getType() const = 0;
};

#endif //GAME_OBJECT_H