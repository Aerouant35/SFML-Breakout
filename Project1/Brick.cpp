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

	//Sound
	soundBuffer = new SoundBuffer;
	sound = new Sound;

	if (!soundBuffer->loadFromFile("../Ressources/Sounds/Pop.wav"))
	{
		// error...
	}
	sound->setVolume(40);
	sound->setBuffer(*soundBuffer);
}


Brick::~Brick()
{
}

/// <summary>
/// Know which side the ball hit a brick and return the new ball direction
/// </summary>
/// <param name="ball">Ball</param>
/// <returns>New ball direction</returns>
Vector2f Brick::BrickCollision(Ball *ball)
{
	// temp vector2f with ball direction
	Vector2f vfNewBallDir = Vector2f(ball->GetDirection().x, ball->GetDirection().y);

	// get all distance between each side
	float fDistLeft = ball->GetRightBound() - this->GetLeftBound();
	float fDistRight = ball->GetLeftBound() - this->GetRightBound();
	float fDistTop = ball->GetBotBound() - this->GetTopBound();
	float fDistBot = ball->GetTopBound() - this->GetBotBound();

	// true if left is inferior to right
	bool ballFromLeft(abs(fDistLeft) < abs(fDistRight));
	// true if top is inferior to bot
	bool ballFromTop(abs(fDistTop) < abs(fDistBot));

	// stock the distance about the previous bool
	float minOverlapX{ ballFromLeft ? fDistLeft : fDistRight };
	float minOverlapY{ ballFromTop ? fDistTop : fDistBot };

	if (abs(minOverlapX) < abs(minOverlapY))
	{
		vfNewBallDir.x *= -1.f;
		return vfNewBallDir;
	}
	else
	{
		vfNewBallDir.y *= -1.f;
		return vfNewBallDir;
	}
	return vfNewBallDir;
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
