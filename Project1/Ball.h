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
		float fRadius;
		Vector2f vfDirection;

	public:
		//inline sf::Vector2f GetPos() { return circle.getPosition(); }

		/*void SetVelocityX(float velocityX) override { fVelocity.x *= velocityX; };
		void SetVelocityY(float velocityY) override { fVelocity.y *= velocityY; };*/

		inline void const SetDirection(const Vector2f direction) { vfDirection = direction; };

		// use sprite
		//sf::Texture* texture;
		//sf::Sprite* Sprite;
		inline sf::Vector2f GetPos() { return sprite->getPosition(); }

		inline float GetLeftBound() { return sprite->getGlobalBounds().left; };
		inline float GetRightBound() { return sprite->getGlobalBounds().left + sprite->getGlobalBounds().width; };
		inline float GetTopBound() { return sprite->getGlobalBounds().top; };
		inline float GetBotBound() { return sprite->getGlobalBounds().top + sprite->getGlobalBounds().height; };

		void CheckWallCollision();
		void Move(float deltaTime);
};

