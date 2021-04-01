#include "Ball.h"


#include "Level.h"


Ball::Ball()
{
	//init var
	strName = "Ball";

    //old (use circle)
	/*
    //set circle radius
    circle.setRadius(fRadius);
    // change la couleur de la forme pour du vert
    circle.setFillColor(sf::Color(100, 250, 50));
    //set origin and position for circle
    GameManager::SetPosition(0.5f, 1, 0.5f, 1, circle);
	*/

    //new (use sprite)
	//Sprite
	texture = new Texture;
	sprite = new Sprite;

	texture->setSmooth(true);
	texture->setRepeated(true);

	fRadius = 90;
	fVelocity = 50.f;
    vfDirection = Vector2f(0.f, 0.f);

	//if(!texture->loadFromFile("Test.png"))
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

        //vfDirection.x = 0;
        //vfDirection.y = 0;
        //GameManager::SetPosition(0.5f, 0.5f, 0.5f, 0.9f, *sprite);
        //gameManager.SetIsMoving(false);

        //remoove refrences

        //get index element 
        int nbToDelete = 0;
        for (nbToDelete; nbToDelete < level->TabGameObject.size(); nbToDelete++)
        {
            if (this == level->TabGameObject[nbToDelete])
            {
                //cout << "REAL - nbToDelete : " << nbToDelete << endl;
                break;
            }
        }
        //cout << "nbToDelete : " << nbToDelete << endl;

        //remoove from tab go*
        //cout << level->TabGameObject.size() << endl;  //debug
        level->TabGameObject.erase(level->TabGameObject.begin() + nbToDelete);
        //cout << level->TabGameObject.size() << endl <<endl; //debug
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
                if (level->TabGameObject[i]->CheckCollision(*this)) //if we detect a collision
                {
                    if (level->TabBrick[i]->BrickCollision(this)) //do the collision function 
                    {
                        //cout << "touch brick " << endl;
                        //if the brick shall be destroyed
                        level->TabGoToDelete.push_back(level->TabBrick[i]);
                        //cout << "TabGoToDelete.size : "<< level->TabGoToDelete.size() << endl;

                        //old
                        //delete level->TabBrick[i];
                        //level->TabGameObject.erase(level->TabGameObject.begin() + i);
                        //level->TabBrick.erase(level->TabBrick.begin() + i);
                    }
                }
            }
                    
        }
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
