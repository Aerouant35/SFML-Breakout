#include "Level.h"


Level::Level()
{
	//background
	texture = new sf::Texture;
	Background = new sf::Sprite;

	texture->setSmooth(true);
	texture->setRepeated(true);

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
			CurrentBrick->sprite->setPosition(	CurrentBrick->fWidth * i + Span * (i + 1) + OffsetLeft,
												CurrentBrick->fHeight * u + Span * (u + 1) + OffsetTop);



			TabBrick.push_back(CurrentBrick);
			TabGameObject.push_back(CurrentBrick);
		}
	}


}

Level::~Level()
{
}

void Level::Update()
{
	//Update All Gameobjects
	for (int i = 0; i < TabGameObject.size(); i++)
	{
		TabGameObject[i]->Update();
	}

	//Check ALL Collisions ( not rly optimise tho )
	//for (int i = 0; i < TabGameObject.size(); i++)
	//{
	//	for (int u = 0; u < TabGameObject.size(); u++)
	//	{
	//		TabGameObject[i]->CheckCollision(*TabGameObject[u]);
	//	}
	//}

	//Check Collisions with the balls
	if (!TabBall.empty()) // if there is any balls
	{
		for (int i = 0; i < TabGameObject.size(); i++) //check each gameobject
		{
			if (TabGameObject[i]->bIgnoreCollision == false) //only if we dont ignore collisions
			{
				for (int u = 0; u < TabBall.size(); u++) //with each balls
				{
					if (TabGameObject[i] != TabBall[u]) // do not check collision with himself
					{
						TabGameObject[i]->CheckCollision(*TabBall[u]);
					}
				}
			}
		}
	}

}
