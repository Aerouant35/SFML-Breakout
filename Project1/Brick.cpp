#include "Brick.h"

Brick::Brick()
{
	//old
	//Shape = new sf::RectangleShape(sf::Vector2f(fWidth, fHeight));
	//Shape->setFillColor(color);


	//Sprite
	texture = new sf::Texture;
	Sprite = new sf::Sprite;


	texture->setSmooth(true);
	texture->setRepeated(true);

	//if(!texture->loadFromFile("Test.png"))
	if (!texture->loadFromFile("../Ressources/Textures/Brick.png"))
	{
		// error...
	}
	Sprite->setTexture(*texture);
	Sprite->scale(1, 1);
}

Brick::~Brick()
{
}
