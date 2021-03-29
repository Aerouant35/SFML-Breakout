#pragma once
#include <SFML/Graphics.hpp>

#include "GameManager.h"
#include "GameObject.h"

class Ball : public GameObject
{
	public : 
		Ball();
		~Ball();

	private : 
		sf::CircleShape circle;

		float fRadius = 10;
		float fVelocity = 300;

	public:

		inline sf::CircleShape& GetShape() { return circle; }
		//inline sf::Vector2f GetPos() { return circle.getPosition(); }
		inline float GetVelocity() { return fVelocity;  }


		// use sprite
		//sf::Texture* texture;
		//sf::Sprite* Sprite;
		inline sf::Vector2f GetPos() { return sprite->getPosition(); }
};

