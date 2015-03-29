#include "Enemy.h"




Enemy::Enemy()
{
	std::string filename = "Pantheon.SheetList";
	//Fail at inheritance u.u
	vel = Vec2f(0,0);
	accel = Vec2f(0,0);
	pos = Vec2f(0,0);
	current = Vec2i(-1,-1);
	currentCell = Vec2i(0,0);
	dt = 0;
	transpThreshold = 128;
	if (StringProc::equalsIgnoreCase (filename.substr(filename.size()-10), ".sheetlist"))
	{
		std::ifstream infile;
		infile.open(filename.c_str());
		assert(infile);
		std::string line;
		int st = 0;
		while (std::getline(infile, line))
		{
			if( StringProc::trim(&line) && (line.at(0) != '#') )
			{
				if(line.length() > 0)
				{
					AnimSheet* as = new AnimSheet(line);
					sheets.push_back(as);
					sheets[st]->setAlphaT(transpThreshold);
					std::vector <std::pair<Vec2<Vec2i>,int> > tempAnims = sheets[st]->getAnims();
					for (unsigned int i = 0; i < tempAnims.size(); i++)
					{
						animations.push_back(std::pair<Vec3<Vec2i>,int>( Vec3<Vec2i> ( Vec2i(st,i), tempAnims[i].first.X() , tempAnims[i].first.Y() ), tempAnims[i].second  ));
					}
					st++;
				}
			}
		}
		baseSize = sheets[0]->getSize();
		infile.close();
		this->setCellTime();
	}
	else
	{
		AnimSheet* as = new AnimSheet(filename);
		sheets.push_back(as);
		sheets[0]->setAlphaT(transpThreshold);
		baseSize = sheets[0]->getSize();
		std::vector<std::pair<Vec2<Vec2i>,int> > tempAnims = sheets[0]->getAnims();
		for (unsigned int i = 0; i < tempAnims.size(); i++)
		{
			animations.push_back( std::pair< Vec3<Vec2i>, int>( Vec3<Vec2i>(Vec2i(0,i), tempAnims[i].first.X() , tempAnims[i].first.Y() ), tempAnims[i].second ) );
		}
		this->setCellTime();

	}
	//ENDFAIL
	attacking = false;
	dead = false;
}

void Enemy::attack()
{
}