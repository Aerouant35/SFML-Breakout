#pragma once
#include <SFML/Graphics.hpp>

//#include "Level.h"

//Debug
#include <iostream>
using namespace std;
using namespace sf;

class GameObject
{
	public :
		GameObject();
		~GameObject();

	protected :
		#pragma region variables
			float fVelocity;
		#pragma endregion variables

	public :
		#pragma region Enum
			enum EnumCollision
			{
				none,
				top,
				bot,
				right,
				left
			};
		#pragma endregion Enum

		#pragma region varialbes
			// use sprite
			Texture* texture;
			Sprite* sprite;
			EnumCollision enumCollision;
		#pragma endregion varialbes

		#pragma region Functions
			void Start();
			void Update();

			bool CheckCollision(GameObject other);
			void OnTriggerEnter(GameObject other);

			inline const float& GetVelocity() { return fVelocity; }

		/*	virtual void SetVelocityX(float velocityX) = 0;
			virtual void SetVelocityY(float velocityY) = 0;*/
		#pragma endregion Functions
};

