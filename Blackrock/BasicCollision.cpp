
#include "BasicCollision.h"


void BasicCollision::Update(Game::iterator it)
{
	while (true)
	{
		if (it.isActive())
		{
			Game::iterator ij = it;
			do
			{
				//... wat?
			}
			while (ij.Next());
		}
		if(!it.Next())
		{
			break;
		}
	}
}