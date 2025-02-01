#include <SFML/Graphics.hpp>
#include "Personaje.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Ball Dash");
    window.setFramerateLimit(60);

    Personaje ball;

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        ball.update();

        window.clear();
        window.draw(ball);
        window.display();
    }

    return 0;
}




