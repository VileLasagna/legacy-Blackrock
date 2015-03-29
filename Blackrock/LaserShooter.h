#include "Sprite.h"
#include "Blackrock.h"


class LaserShooter
{
public:

	LaserShooter();
	void Fire();
	bool Update(Blackrock* BR);
	void Draw();
	void setLevel(int i);
	void levelUp() {level++;}
	bool WaveClear();
	void Reset();

private:

	std::vector<Sprite*> lasers;
	int level;
	SoundFX* lasfire;
	bool clear;
};

