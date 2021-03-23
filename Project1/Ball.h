#pragma once
#include <SFML/Graphics.hpp>

#include "GameManager.h"

class Ball
{
	sf::CircleShape circle;

	float fRadius = 10;
	float fVelocity = 300;

	public:
		Ball();
		~Ball();

		inline sf::CircleShape GetShape() { return circle; }
		inline sf::Vector2f GetPos() { return circle.getPosition(); }
		inline float GetVelocity() { return fVelocity;  }
};

