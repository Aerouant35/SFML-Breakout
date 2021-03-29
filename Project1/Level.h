#pragma once

#include <vector>

#include "Ball.h"
#include "Brick.h"
#include "GameObject.h"


class Level
{
	public:
		Level();
		~Level();

	private:

		float OffsetTop = 20;
		float OffsetLeft = 30;
		int Span = 18;

	public : 

		int nbRaw = 3;
		int nbCol = 8;
		
		std::vector<Ball*> TabBall;
		std::vector<Brick*> TabBrick;
		std::vector<GameObject*> TabGameObject;

		sf::Texture* texture;
		sf::Sprite* Background;

		#pragma region Functions
		void Update();
		#pragma endregion Functions

};

