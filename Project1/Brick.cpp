#include "Brick.h"

Brick::Brick()
{
	Shape = new sf::RectangleShape(sf::Vector2f(fWidth, fHeight));
	Shape->setFillColor(color);
}

Brick::~Brick()
{
}
