#pragma once
#include <SFML/Graphics.hpp>

//#include "Level.h"

//Debug
#include <iostream>
using namespace std;

class GameObject
{
	public :
		GameObject();
		~GameObject();

	protected :

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
			sf::Texture* texture;
			sf::Sprite* sprite;
			EnumCollision enumCollision;
		#pragma endregion varialbes

		#pragma region Functions
			void Start();
			void Update();

			bool CheckCollision(GameObject other);
			void OnTriggerEnter(GameObject other);
		#pragma endregion Functions
};

