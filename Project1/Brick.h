#pragma once
#include <SFML/Graphics.hpp>



class Brick
{

public:
	Brick();
	~Brick();

private:


public:
	int nbLife = 3;

	float fWidth = 50;
	float fHeight = 20;

	// d�finit un rectangle
	sf::RectangleShape *Shape;

	sf::Color color = sf::Color::Red;
	

};

