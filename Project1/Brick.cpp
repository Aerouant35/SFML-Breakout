#include "Brick.h"

Brick::Brick() : GameObject()
{

	//old
	//Shape = new sf::RectangleShape(sf::Vector2f(fWidth, fHeight));
	//Shape->setFillColor(color);


	//Sprite
	
	texture = new sf::Texture;
	sprite = new sf::Sprite;

	texture->setSmooth(true);
	texture->setRepeated(true);

	//if(!texture->loadFromFile("Test.png"))
	if (!texture->loadFromFile("../Ressources/Textures/Brick.png"))
	{
		// error...
	}
	sprite->setTexture(*texture);
	sprite->scale(1, 1);
}


Brick::~Brick()
{
}
