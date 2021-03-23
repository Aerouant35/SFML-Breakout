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
		int nbCol = 9;

		std::vector<Brick*> TabBrick;
};

