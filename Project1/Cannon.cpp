#include "Cannon.h"

Cannon::Cannon()
{
}

Cannon::~Cannon()
{
}

sf::Vector2f Cannon::BallDir(Ball& ball, sf::Vector2f mousePos)
{
	sf::Vector2f vectorDiff = mousePos - ball.GetPos();
	sf::Vector2f vectorNorm = GameManager::Normalize(vectorDiff);

	return vectorNorm;
}
