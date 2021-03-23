#pragma once
#include <SFML/Graphics.hpp>

#include "Ball.h"

class Cannon
{
	public:
		sf::Vector2f BallMove(Ball& ball, sf::Vector2f mousePos);
};

