#include "board.h"

Board::Board(int size_x, int size_y)
{
	this->size_x = size_x;
	this->size_y = size_y;

	int size = size_x * size_y;
	matrix = new int[size] {};
}

Board::~Board()
{
	delete matrix;
}

int Board::get_element(int x, int y)
{
	if (!is_in_bounds(x, y)) {
		return 0;
	}

	int index = get_index(x, y);
	return matrix[index];
}

void Board::set_element(int x, int y, int value)
{
	if (!is_in_bounds(x, y)) {
		return;
	}

	int index = get_index(x, y);
	matrix[index] = value;
}

int Board::get_size_x()
{
	return this->size_x;
}

int Board::get_size_y()
{
	return this->size_y;
}

bool Board::is_in_bounds(int x, int y)
{
	return x >= 0 and x < size_x and y >= 0 and y < size_y;
}

int Board::get_index(int x, int y)
{
	return x + y * size_x;
}
