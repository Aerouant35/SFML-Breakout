#include "Cannon.h"

sf::Vector2f Cannon::BallMove(Ball& ball, sf::Vector2f mousePos)
{
	GameManager tempManager;

	sf::Vector2f vectorDiff = mousePos - ball.GetPos();
	sf::Vector2f vectorNorm = tempManager.Normalize(vectorDiff);

	return vectorNorm;
}
