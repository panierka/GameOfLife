#pragma once
#include <SFML/Graphics.hpp>
#include"board.h"

const int MAP_SIZE_X = 250;
const int MAP_SIZE_Y = 200;
const int CELL_SIZE = 4;

class Simulation 
{
	private:
		Board* board;
		bool is_frozen;

	public:
		Simulation();
		~Simulation();
		void update_display(sf::RenderWindow&);
		void update_cells();
		void set_is_frozen(bool);

	private:
		int count_cell_neighbours(int x, int y);
		void fill_board_randomly(int elements);
};