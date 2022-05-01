#pragma once
#include <SFML/Graphics.hpp>
#include"board.h"

const int MAP_SIZE_X = 160;
const int MAP_SIZE_Y = 120;
const int CELL_SIZE = 6;

class Simulation 
{
	private:
		Board board;

	public:
		Simulation();
		void update(sf::RenderWindow&);
};
