#include "GameObject.h"

#include <iostream>


GameObject::GameObject()
{

}


GameObject::~GameObject()
{
}

void GameObject::Start()
{
}

void GameObject::Update(float* deltaTime)
{

}

bool GameObject::CheckCollision(GameObject other)
{
	//doc FloatRect : https://docs.rs/sfml/0.9.3/sfml/graphics/struct.FloatRect.html

	//checkt collision Up

	//checkt collision Bottom
	/*
	if ((sprite->getGlobalBounds().top + sprite->getGlobalBounds().height) > other.sprite->getGlobalBounds().top)
	{
		enumCollision = EnumCollision::bot;
	}
	*/

	//checkt collision Left

	//checkt collision Right


	//Detect the global collision
	if (sprite->getGlobalBounds().intersects(other.sprite->getGlobalBounds()))
	{
		OnTriggerEnter(other);
		return true;
	}
	else
	{
		return false;
	}

}

void GameObject::OnTriggerEnter(GameObject other)
{
	//Debug
	//std::cout << this->strName << " Collision with " << other.strName  << std::endl;
}
