#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

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

	sf::Texture* textureUnbreakable;
	sf::Texture* texture1;
	sf::Texture* texture2;
	sf::Texture* texture3;

	SoundBuffer* soundBuffer;
	Sound* sound;
	#pragma endregion varialbes

	#pragma region Functions
	Vector2f BrickCollision(Ball* ball);
	void UpdateTexture();
	#pragma endregion Functions
};

