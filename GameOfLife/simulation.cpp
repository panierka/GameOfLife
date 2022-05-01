#include "simulation.h"

void Simulation::update(sf::RenderWindow& window)
{
    window.clear(sf::Color::Black);

    auto circle = sf::CircleShape(10);
    circle.setFillColor(sf::Color(255, 0, 255));
    window.draw(circle);

    window.display();
}