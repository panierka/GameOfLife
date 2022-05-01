#pragma once

class Board {
	private:
		int* matrix;
		int size_x;
		int size_y;

	public:
		Board(int size_x, int size_y);

		int get(int x, int y);
		void set(int x, int y, int value);
			
	private:
		bool is_in_bounds(int x, int y);
		int get_index(int x, int y);
};