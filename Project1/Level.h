#pragma once
#include "Brick.h"
#include <vector>


class Level
{
	public:
		Level();
		~Level();

	private:

		float OffsetTop = 20;
		float OffsetLeft = 30;
		int Span = 18;

	public : 

		int nbRaw = 3;
		int nbCol = 8;

		std::vector<Brick*> TabBrick;

		sf::Texture* texture;
		sf::Sprite* Background;
};

