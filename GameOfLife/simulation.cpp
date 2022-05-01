#include "simulation.h"
#include <iostream>

Simulation::Simulation()
{
    board = new Board(MAP_SIZE_X, MAP_SIZE_Y);
    is_frozen = false;
    fill_board_randomly(MAP_SIZE_X * MAP_SIZE_Y / 8);
}

Simulation::~Simulation()
{
    delete board;
}

void Simulation::update_display(sf::RenderWindow& window)
{
    window.clear(sf::Color::Black);

    for (int y = 0; y < board->get_size_y(); y++) 
    {
        for (int x = 0; x < board->get_size_x(); x++)
        {
            if (board->get_element(x, y) == 0)
            {
                continue;
            }

            auto size = sf::Vector2f(CELL_SIZE, CELL_SIZE);
            auto logical_pixel_representation = sf::RectangleShape(size);
            logical_pixel_representation.setFillColor(sf::Color::White);

            auto center = sf::Vector2f(0, 0);
            auto position = sf::Vector2f(x * CELL_SIZE, y * CELL_SIZE);
            logical_pixel_representation.setOrigin(center);
            logical_pixel_representation.setPosition(position);

            window.draw(logical_pixel_representation);
        }
    }

    window.display();
}

void Simulation::update_cells()
{
    if (is_frozen) 
    {
        return;
    }

    Board* future = new Board(board->get_size_x(), board->get_size_y());

    for (int y = 0; y < board->get_size_y(); y++)
    {
        for (int x = 0; x < board->get_size_x(); x++)
        {
            int cell = board->get_element(x, y);
            int neighbours_count = count_cell_neighbours(x, y);

            if (cell == 0) 
            {
                if (neighbours_count == 3) 
                {
                    future->set_element(x, y, 1);
                }

                continue;
            }
            
            if (neighbours_count < 2) 
            {
                future->set_element(x, y, 0);
                continue;
            }

            if (neighbours_count > 3) 
            {
                future->set_element(x, y, 0);
                continue;
            }

            future->set_element(x, y, cell);
        }
    }

    delete board;
    board = future;
}

void Simulation::set_is_frozen(bool is_frozen)
{
    this->is_frozen = is_frozen;
}

int Simulation::count_cell_neighbours(int x, int y)
{
    int sum = 0;
    for (int dy = -1; dy <= 1; dy++) 
    {
        for (int dx = -1; dx <= 1; dx++) 
        {
            if (dx == 0 and dy == 0) 
            {
                continue;
            }

            sum += board->get_element(x + dx, y + dy);
        }
    }

    return sum;
}

void Simulation::fill_board_randomly(int elements)
{
    while (elements > 0) 
    {
        int x = rand() % board->get_size_x();
        int y = rand() % board->get_size_y();

        board->set_element(x, y, 1);

        elements--;
    }
}
