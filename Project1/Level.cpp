#include "Level.h"

Level::Level()
{
	int Span = 10;

	//Create Bricks on the Map
	for (int u = 0; u < nbRaw; u++)
	{
		for (int i = 0; i < nbCol; i++)
		{
			Brick* CurrentBrick = new Brick;

			//set pos
			CurrentBrick->Shape->setPosition(CurrentBrick->fWidth * i + Span * (i+1), CurrentBrick->fHeight * u + Span * (u+1) );

			TabBrick.push_back(CurrentBrick);
		}
	}


}

Level::~Level()
{
}
