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

	float fDistLeft = ball->GetRightBound() - this->GetLeftBound();
	float fDistRight = ball->GetLeftBound() - this->GetRightBound();
	float fDistTop = ball->GetBotBound() - this->GetTopBound();
	float fDistBot = ball->GetTopBound() - this->GetBotBound();

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
