#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Ball.h"


class Brick : public GameObject
{

public:
	Brick();
	~Brick();
		
private:


public:
	#pragma region varialbes
	int nbLife = NULL;

	float fWidth = 100;
	float fHeight = 35;

	// définit un rectangle ( old - to delete)
	//sf::RectangleShape *Shape;
	//sf::Color color = sf::Color::Red;
	
	// use sprite ( new  - heritate from GameObject)
	//sf::Texture* texture;
	//sf::Sprite* Sprite;
	#pragma endregion varialbes

	#pragma region Functions
	bool BrickCollision(Ball* ball);

	#pragma endregion Functions
};

