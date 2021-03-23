#include "Level.h"

Level::Level()
{
	int Span = 10;

	//Create Bricks on the Map
	for (int i = 0; i < nbCol; i++)
	{
		Brick *CurrentBrick = new Brick;

		// change sa taille en 100x100

		CurrentBrick->Shape->setSize(sf::Vector2f(100, 100));
		// change la couleur de la forme pour du vert
		CurrentBrick->Shape->setFillColor(CurrentBrick->color);
		//set pos
		CurrentBrick->Shape->setPosition(CurrentBrick->fWidth * i + Span, Span); //pb ici ?

		TabBrick.push_back(CurrentBrick);
	}

}

Level::~Level()
{
}
