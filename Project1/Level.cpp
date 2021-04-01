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


	//Map Creation :
	//--------------
	// Null = no item to create
	// 0 = Unbreakable brick 
	// 1 = brick 1 life
	// 2 = brick 2 life
	// 3 = brick 3 life

	std::vector<std::vector<int>> matrixMap = 
	{ 
		{3,2,1,1,1,1,2,3},
		{2,1,2,NULL,NULL,2,1,2},
		{3,NULL,1,NULL,NULL,1,NULL,3},
		{-1,NULL,-1,3,3,-1,NULL,-1},
		{NULL,NULL,NULL,-1,-1,NULL,NULL,NULL}
	};

	//Create Bricks on the Map
	for (int u = 0; u < nbRaw; u++)
	{
		for (int i = 0; i < nbCol; i++)
		{

			if (matrixMap[u][i] != NULL)
			{
				Brick* CurrentBrick = new Brick;
				CurrentBrick->setLevel(this);
				CurrentBrick->nbLife = matrixMap[u][i];
				CurrentBrick->UpdateTexture();

				//set pos
				CurrentBrick->sprite->setPosition(CurrentBrick->fWidth * i + Span * (i + 1) + OffsetLeft,
					CurrentBrick->fHeight * u + Span * (u + 1) + OffsetTop);

				TabBrick.push_back(CurrentBrick);
				TabGameObject.push_back(CurrentBrick);
			}
		}
	}
}

Level::~Level()
{
}

void Level::Update(float *deltaTime)
{
	//Update All Gameobjects
	for (int i = 0; i < TabGameObject.size(); i++)
	{
		TabGameObject[i]->Update(deltaTime);
	}

	//for each GO to delete
	for (int i = TabGoToDelete.size() - 1; i >= 0 ; i--)
	{

		//remove go from tab go
		for (int u = TabGameObject.size() - 1; u >= 0; u--)
		{
			if (TabGoToDelete[i] == TabGameObject[u])
			{
				TabGameObject.erase(TabGameObject.begin() + u);
			}
		}

		//remove go from tab brick
		for (int v = TabBrick.size() - 1; v >= 0; v--)
		{
			if (TabGoToDelete[i] == TabBrick[v])
			{
				TabBrick.erase(TabBrick.begin() + v);
			}
		}

		//Remove go from TabGoToDelete
		delete TabGoToDelete[i];
		TabGoToDelete.erase(TabGoToDelete.begin() + i);
	}
}
