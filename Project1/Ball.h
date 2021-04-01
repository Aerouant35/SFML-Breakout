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
		bool bIsCollide;

	public:
		#pragma region PublicFunction
			void Update(float * DeltaTime) override;

			void CheckWallCollision();
			void CheckBrickCollision();
			void Move(float* deltaTime);

			inline Vector2f GetDirection() { return vfDirection; };
			inline void const SetDirection(const Vector2f direction) { vfDirection = direction; };

			inline sf::Vector2f GetPos() { return sprite->getPosition(); }
		#pragma endregion PublicFunction
};

