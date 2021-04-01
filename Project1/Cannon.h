#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "GameObject.h"


#pragma region Forward Declarations
	class Ball;
	class level;
#pragma endregion Forward Declarations

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
			Texture* textureLoaded;
			Texture* textureUnloaded;

			SoundBuffer* soundBuffer;
			Sound* sound;
		#pragma region Variables

		#pragma region Functions
			virtual void Start();
			virtual void Update(float* deltaTime);

			Vector2f BallDir(Ball& ball, sf::Vector2f mousePos);
			RenderWindow* renderWindow;

			void Rotate();
			void ChangeTexture();
			void Fire(Level* level);
			void Load();
		#pragma endregion Functions
};

