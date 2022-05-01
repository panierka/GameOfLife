#pragma once

class Board {
	private:
		int* matrix;
		int size_x;
		int size_y;

	public:
		Board(int size_x, int size_y);
		~Board();

		int get_element(int x, int y);
		void set_element(int x, int y, int value);

		int get_size_x();
		int get_size_y();
			
	private:
		bool is_in_bounds(int x, int y);
		int get_index(int x, int y);
};