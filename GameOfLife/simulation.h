#pragma once
#include <SFML/Graphics.hpp>

const int MAP_SIZE_X = 256;
const int MAP_SIZE_Y = 256;
const int CELL_SIZE = 4;

class Simulation 
{
	public:
		void update(sf::RenderWindow&);
};
