#include "simulation.h"
#include <time.h>

int main()
{
    int screen_size_x = MAP_SIZE_X * CELL_SIZE;
    int screen_size_y = MAP_SIZE_Y * CELL_SIZE;

    sf::RenderWindow window(sf::VideoMode(screen_size_x, screen_size_y), "Game of Life", sf::Style::Titlebar | sf::Style::Close);

    srand(time(NULL));
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
        
        simulation.update_display(window);

        sf::sleep(sf::seconds(1.f / 40.f));
        simulation.update_cells();
    }
    
    return 0;
}