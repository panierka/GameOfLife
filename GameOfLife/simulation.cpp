#include "simulation.h"

Simulation::Simulation() : board(MAP_SIZE_X, MAP_SIZE_Y)
{

}

void Simulation::update(sf::RenderWindow& window)
{
    window.clear(sf::Color::Black);

    for (int y = 0; y < MAP_SIZE_Y; y++) 
    {
        for (int x = 0; x < MAP_SIZE_X; x++) 
        {
            if ((x + y) % 16 != 0) {
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