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
		
		vector<Ball*> TabBall;
		vector<Brick*> TabBrick;
		vector<GameObject*> TabGameObject;

		Texture* texture;
		Sprite* Background;

		#pragma region Functions
		void Update(float deltaTime);
		#pragma endregion Functions

};

