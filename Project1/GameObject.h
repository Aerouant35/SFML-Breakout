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
			string strName = "GameObject";
			string strTag = "none";

			sf::Texture* texture;
			sf::Sprite* sprite;

			EnumCollision enumCollision;
			bool bIgnoreCollision = false;
		#pragma endregion varialbes

		#pragma region Functions
			virtual void Start();
			virtual void Update();

			virtual bool CheckCollision(GameObject other);
			virtual void OnTriggerEnter(GameObject other);
		#pragma endregion Functions
};

