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
