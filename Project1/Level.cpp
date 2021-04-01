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
		{3,1,NULL,3,1,1,2,3},
		{2,1,3,1,1,1,NULL,1},
		{1,1,2,1,NULL,1,1,3}
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
	for (int i = TabGoToDelete.size(); i > 0 ; i--)
	{

		//remove go from tab go
		for (int u = TabGameObject.size(); u > 0; u--)
		{
			if (TabGoToDelete[i-1] == TabGameObject[u-1])
			{
				TabGameObject.erase(TabGameObject.begin() + u-1);
			}
		}

		//remove go from tab brick
		for (int v = TabBrick.size(); v >0; v--)
		{
			if (TabGoToDelete[i-1] == TabBrick[v-1])
			{
				TabBrick.erase(TabBrick.begin() + v-1);
			}
		}

		//Remove go from TabGoToDelete
		delete TabGoToDelete[i-1];
		TabGoToDelete.erase(TabGoToDelete.begin() + i - 1);

		//cout << "brick removed "<< endl;
	}

}
