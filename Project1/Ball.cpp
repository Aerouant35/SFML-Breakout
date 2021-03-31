#include "Ball.h"

Ball::Ball()
{
	//init var
	strName = "Ball";

    //old (use circle)
	/*
    //set circle radius
    circle.setRadius(fRadius);
    // change la couleur de la forme pour du vert
    circle.setFillColor(sf::Color(100, 250, 50));
    //set origin and position for circle
    GameManager::SetPosition(0.5f, 1, 0.5f, 1, circle);
	*/

    //new (use sprite)
	//Sprite
	texture = new sf::Texture;
	sprite = new sf::Sprite;

	texture->setSmooth(true);
	texture->setRepeated(true);

	//if(!texture->loadFromFile("Test.png"))
	if (!texture->loadFromFile("../Ressources/Textures/Ball.png"))
	{
		// error...
	}
	sprite->setTexture(*texture);
	sprite->scale(0.05, 0.05);

	sprite->setPosition(GameManager::fWidth / 2, GameManager::fHeight - 50);

	GameManager::SetPosition(0.5f, 0.5f, 0.5f, 0.9f, *sprite);
}

Ball::~Ball()
{
}
