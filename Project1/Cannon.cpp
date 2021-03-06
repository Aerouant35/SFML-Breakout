#include "Cannon.h"

#include "Ball.h"
#include "level.h";

Cannon::Cannon()
{

}

Cannon::Cannon(sf::RenderWindow* CurrentWindow)
{	//init var
	bIgnoreCollision = true;
	renderWindow = CurrentWindow;

	//load textures
	textureLoaded = new sf::Texture;
	textureUnloaded = new sf::Texture;

	if (!textureLoaded->loadFromFile("../Ressources/Textures/CanonLoaded.png"))
	{
		// error...
	}
	if (!textureUnloaded->loadFromFile("../Ressources/Textures/CanonUnloaded.png"))
	{
		// error...
	}

	//Set Sprite
	texture = new sf::Texture;
	sprite = new sf::Sprite;

	//smooth textures
	texture->setSmooth(true);
	textureLoaded->setSmooth(true);
	textureUnloaded->setSmooth(true);

	ChangeTexture();

	sprite->scale(0.1, 0.1);

	sprite->setPosition(GameManager::fWidth / 2, GameManager::fHeight - 50);

	GameManager::SetPosition(0.5f, 0.5f, 0.5f, 0.9f, *sprite);

	//Sound
	soundBuffer = new SoundBuffer;
	sound = new Sound;

	if (!soundBuffer->loadFromFile("../Ressources/Sounds/Laser.wav"))
	{
		// error...
	}
	sound->setBuffer(*soundBuffer);
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

void Cannon::Start()
{
}

void Cannon::Update(float* deltaTime)
{
	//cout << "Update Canon" << endl;
	Rotate();
}

void Cannon::Rotate()
{
	//angle in degrees of rotation for sprite
	float mouseAngle = -atan2(	sf::Mouse::getPosition(*renderWindow).x - sprite->getPosition().x,
								sf::Mouse::getPosition(*renderWindow).y - sprite->getPosition().y) * 180 / 3.14159 + 180; 

	//apply rotation
	sprite->setRotation(mouseAngle);

}

void Cannon::ChangeTexture()
{
	if (bIsLoaded)
	{
		sprite->setTexture(*textureLoaded);
	}
	else
	{
		sprite->setTexture(*textureUnloaded);
	}
}

void Cannon::Fire(Level* level)
{
	//instanciate ball
	Ball* ball = new Ball();
	ball->setLevel(level);

	level->TabBall.push_back(ball);
	level->TabGameObject.push_back(ball);

	//update sprite texture
	bIsLoaded = false;
	ChangeTexture();

	//Sound
	sound->play();
}

void Cannon::Load()
{
	bIsLoaded = true;
	ChangeTexture();
}
