#include "simulation.h"

int main()
{
    int screen_size_x = MAP_SIZE_X * CELL_SIZE;
    int screen_size_y = MAP_SIZE_Y * CELL_SIZE;

    sf::RenderWindow window(sf::VideoMode(screen_size_x, screen_size_y), "Game of Life");
    Simulation simulation;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        simulation.update(window);
    }
    
    return 0;
}