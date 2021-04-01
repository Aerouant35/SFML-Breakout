#pragma once

#include <vector>

#include "GameObject.h"


#include "Ball.h"
#include "Brick.h"
#include "Cannon.h"


class Level
{
	public:
		Level();
		~Level();

	private:
		#pragma region Variables
			float OffsetTop = 20;
			float OffsetLeft = 30;
			int Span = 18;
		#pragma endregion Variables

	public : 
		#pragma region Variables
			int nbRaw = 4;
			int nbCol = 8;
			float deltaTime = 0;
		
			Cannon* cannon;

			vector<Ball*> TabBall;
			vector<Brick*> TabBrick;

			vector<GameObject*> TabGameObject;
			vector<GameObject*> TabGoToDelete;

			Texture* texture;
			Sprite* Background;
		#pragma endregion Variables

		#pragma region Functions
			void Update(float *deltaTime);
		#pragma endregion Functions

};

