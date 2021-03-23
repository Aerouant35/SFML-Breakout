#include "Ball.h"

Ball::Ball()
{
    GameManager tempManager;
	
    //set circle radius
    circle.setRadius(fRadius);
    // change la couleur de la forme pour du vert
    circle.setFillColor(sf::Color(100, 250, 50));
    //set origin and position for circle
    tempManager.SetPosition(0.5f, 1, 0.5f, 1, circle);
}

Ball::~Ball()
{
}
