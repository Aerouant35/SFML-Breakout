#include "Level.h"

Level::Level()
{
	//background
	texture = new sf::Texture;
	Background = new sf::Sprite;
	

	texture->setSmooth(true);
	texture->setRepeated(true);

	//if(!texture->loadFromFile("Test.png"))
	if (!texture->loadFromFile("../Ressources/Textures/BackGround.png"))
	{
		// error...
	}
	Background->setTexture(*texture);
	Background->scale(1, 1);
	Background->setPosition(0, 0);




	//Create Bricks on the Map
	for (int u = 0; u < nbRaw; u++)
	{
		for (int i = 0; i < nbCol; i++)
		{
			Brick* CurrentBrick = new Brick;

			//set pos

			//old ( rectangle )
			/*
			CurrentBrick->Shape->setPosition(	CurrentBrick->fWidth * i + Span * (i+1)  + OffsetLeft,
												CurrentBrick->fHeight * u + Span * (u+1) + OffsetTop	);
			*/

			//new ( sprite )
			CurrentBrick->Sprite->setPosition(	CurrentBrick->fWidth * i + Span * (i + 1) + OffsetLeft,
												CurrentBrick->fHeight * u + Span * (u + 1) + OffsetTop);



			TabBrick.push_back(CurrentBrick);
		}
	}


}

Level::~Level()
{
}
