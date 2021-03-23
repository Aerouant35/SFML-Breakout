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

	float fWidth = 100;
	float fHeight = 35;

	// définit un rectangle
	sf::RectangleShape *Shape;

	sf::Color color = sf::Color::Red;
	

};

