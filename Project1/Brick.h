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
	#pragma endregion varialbes

	#pragma region Functions
	bool BrickCollision(Ball* ball);

	#pragma endregion Functions
};

