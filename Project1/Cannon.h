#pragma once
#include <SFML/Graphics.hpp>


class Cannon
{
	public :

		Cannon();
		~Cannon();

	private :

	public :

		float fMouseX;
		float fMouseY;

		float fWidth = 100;
		float fHeight = 100;

		// d�finit un rectangle

		//sf::Image
		sf::RectangleShape* Shape;



};

