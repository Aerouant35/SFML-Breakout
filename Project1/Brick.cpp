#include "Brick.h"

#include "Level.h"

Brick::Brick() : GameObject()
{
	//init var
	strName = "Brick";

	//Sprite	
	sprite = new sf::Sprite;

	//load textures
	texture					= new sf::Texture;
	textureUnbreakable		= new sf::Texture;
	texture1				= new sf::Texture;
	texture2				= new sf::Texture;
	texture3				= new sf::Texture;
	
	texture->setSmooth(true);
	texture->setRepeated(true);

	//if(!texture->loadFromFile("Test.png"))
	if (!texture->loadFromFile("../Ressources/Textures/Brick.png"))
	{
		// error...
	}
	if (!textureUnbreakable->loadFromFile("../Ressources/Textures/Brick-Unbreakable.png"))
	{
		// error...
	}
	if (!texture1->loadFromFile("../Ressources/Textures/Brick-1.png"))
	{
		// error...
	}
	if (!texture2->loadFromFile("../Ressources/Textures/Brick-2.png"))
	{
		// error...
	}
	if (!texture3->loadFromFile("../Ressources/Textures/Brick-3.png"))
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

void Brick::UpdateTexture()
{
	if (nbLife == -1)
	{
		sprite->setTexture(*textureUnbreakable);
	}

	if (nbLife == 1)
	{
		sprite->setTexture(*texture1);
	}

	if (nbLife == 2)
	{
		sprite->setTexture(*texture2);
	}

	if (nbLife == 3)
	{
		sprite->setTexture(*texture3);
	}

}
