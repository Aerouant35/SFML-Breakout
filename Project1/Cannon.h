#pragma once
#include <SFML/Graphics.hpp>

#include "GameObject.h"
#include "Ball.h"
#include "level.h";

class Cannon : public GameObject
{
	public :

		Cannon();
		Cannon(sf::RenderWindow* CurrentWindow);
		~Cannon();

	private :

	public :
		#pragma region Variables
			float fMouseX;
			float fMouseY;

			float fWidth = 100;
			float fHeight = 100;

			bool bIsLoaded = true;
			sf::Texture* textureLoaded;
			sf::Texture* textureUnloaded;
		#pragma region Variables

		#pragma region Functions
			virtual void Start();
			virtual void Update();

			sf::Vector2f BallDir(Ball& ball, sf::Vector2f mousePos);
			sf::RenderWindow* renderWindow;

			void Rotate();
			void ChangeTexture();
			void Fire(Level* level);
			void Load();
		#pragma endregion Functions
};

