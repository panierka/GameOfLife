#include "board.h"

Board::Board(int size_x, int size_y)
{
	this->size_x = size_x;
	this->size_y = size_y;

	size_t size = (size_t)size_x * size_y;
	matrix = new int[size];
}

int Board::get(int x, int y)
{
	if (!is_in_bounds(x, y)) {
		return 0;
	}

	int index = get_index(x, y);
	return matrix[index];
}

void Board::set(int x, int y, int value)
{
	if (!is_in_bounds(x, y)) {
		return;
	}

	int index = get_index(x, y);
	matrix[index] = value;
}

bool Board::is_in_bounds(int x, int y)
{
	return x >= 0 and x < size_x and y >= 0 and y < size_y;
}

int Board::get_index(int x, int y)
{
	return x + y * size_x;
}
