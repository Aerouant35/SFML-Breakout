#pragma once
#include "Brick.h"
#include <vector>


class Level
{
	public:
		Level();
		~Level();

	private:

	public : 

		int nbRaw = 3;
		int nbCol = 5;

		std::vector<Brick*> TabBrick;
};

