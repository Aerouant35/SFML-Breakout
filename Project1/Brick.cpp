#include "Brick.h"

#include "Level.h"

Brick::Brick() : GameObject()
{
	//init var
	strName = "Brick";

	//old
	//Shape = new sf::RectangleShape(sf::Vector2f(fWidth, fHeight));
	//Shape->setFillColor(color);


	//Sprite
	
	texture = new sf::Texture;
	sprite = new sf::Sprite;

	texture->setSmooth(true);
	texture->setRepeated(true);

	//if(!texture->loadFromFile("Test.png"))
	if (!texture->loadFromFile("../Ressources/Textures/Brick.png"))
	{
		// error...
	}
	sprite->setTexture(*texture);
	sprite->scale(1, 1);
}


Brick::~Brick()
{
}

bool Brick::BrickCollision(Ball *ball)
{
	Vector2f vfNewBallDir;
	FloatRect frBound = sprite->getGlobalBounds();

	float fLeftBound = frBound.left;
	float fRightBound = frBound.left + frBound.width;
	float fTopBound = frBound.top;
	float fBotBound = frBound.top + frBound.height;

	float fDistLeft = ball->GetRightBound() - fLeftBound;
	float fDistRight = ball->GetLeftBound() - fRightBound;
	float fDistTop = ball->GetBotBound() - fTopBound;
	float fDistBot = ball->GetTopBound() - fBotBound;

	bool ballFromLeft(abs(fDistLeft) < abs(fDistRight));
	bool ballFromTop(abs(fDistTop) < abs(fDistBot));

	float minOverlapX{ ballFromLeft ? fDistLeft : fDistRight };
	float minOverlapY{ ballFromTop ? fDistTop : fDistBot };

	if (abs(minOverlapX) < abs(minOverlapY))
	{
		vfNewBallDir.x = ball->GetDirection().x * -1.f;
		vfNewBallDir.y = ball->GetDirection().y;

		ball->SetDirection(vfNewBallDir);
		return true;
	}
	else
	{
		vfNewBallDir.x = ball->GetDirection().x;
		vfNewBallDir.y = ball->GetDirection().y * -1.f;

		ball->SetDirection(vfNewBallDir);
		return true;
	}
	return false;
}
