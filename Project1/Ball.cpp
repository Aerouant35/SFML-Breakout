#include "Ball.h"
#include <SFML/Audio.hpp>

#include "Level.h"


Ball::Ball()
{
	//init var
	strName = "Ball";

	//Sprite
	texture = new Texture;
	sprite = new Sprite;

	texture->setSmooth(true);
	texture->setRepeated(true);

	fRadius = 90;
	fVelocity = 50.f;
    vfDirection = Vector2f(0.f, 0.f);
    bIsCollide = false;

	if (!texture->loadFromFile("../Ressources/Textures/Ball.png"))
	{
		// error...
	}
	sprite->setTexture(*texture);
	sprite->scale(0.05, 0.05);

	sprite->setPosition(GameManager::fWidth / 2, GameManager::fHeight - 50);

	GameManager::SetPosition(0.5f, 0.5f, 0.5f, 0.9f, *sprite);
}

Ball::~Ball()
{
}

void Ball::CheckWallCollision()
{
    
    if (GetLeftBound() <= 0.f || GetRightBound() >= GameManager::fWidth)
    {
        vfDirection.x *= -1.f;

    }
    else if (GetTopBound() <= 0.f)
    {
        vfDirection.y *= -1.f;
    }

    //reset ball when falling bottom wall
    else if (GetTopBound() > GameManager::fHeight)
    {
        //reset Canon
        level->cannon->Load();

        //get index element 
        int nbToDelete = 0;
        for (nbToDelete; nbToDelete < level->TabGameObject.size(); nbToDelete++)
        {
            if (this == level->TabGameObject[nbToDelete])
            {
                break;
            }
        }

        //remoove from tab go*
        level->TabGameObject.erase(level->TabGameObject.begin() + nbToDelete);

        //remoove from tab ball
        level->TabBall.clear();

        //delete element
         delete this;
    }
}

void Ball::CheckBrickCollision()
{

        for (int i = 0; i < level->TabGameObject.size(); i++) //check each gameobject
        {
            if (level->TabGameObject[i]->strName == "Brick") //if the go is a brick
            {
                if (level->TabGameObject[i]->CheckCollision(*this) && !bIsCollide) //if we detect a collision
                {
                    bIsCollide = true; //Set true to collide one brick

                    //Set new ball direction when it hit a brick
                    SetDirection(level->TabBrick[i]->BrickCollision(this));  

                    //if the brick shall be damaged
                    if (level->TabBrick[i]->nbLife > 0)
                    {
                        level->TabBrick[i]->nbLife -= 1;
                        level->TabBrick[i]->UpdateTexture();

                    }
                    //if the brick shall be destroyed
                    if (level->TabBrick[i]->nbLife == 0)
                    {
                        level->TabGoToDelete.push_back(level->TabBrick[i]);
                    }

                    //Play sound
                    level->TabBrick[i]->sound->play();
                }
            }
                    
        }
        bIsCollide = false; //reset to false
}

void Ball::Update(float* DeltaTime)
{
    Move(DeltaTime);
    CheckBrickCollision();
    CheckWallCollision(); //might destroy imself, so last to call
}

void Ball::Move(float* deltaTime)
{
    //Spicyyyyyy :
    float fSpeed = 15;

    sprite->move(vfDirection * GetVelocity() * *deltaTime * fSpeed);
}
