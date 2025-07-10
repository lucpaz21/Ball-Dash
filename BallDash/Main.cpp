#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <ctime>
#include "Personaje.h"
#include "Moneda.h"
#include "PowerUp.h"

int main() {

    std::srand((unsigned)std::time(0));

    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Ball Dash");
    window.setFramerateLimit(60);

    sf::Font font;
    font.openFromFile("pixel.ttf");
    sf::Text text(font);

    text.setFont(font);
    

    Personaje ball;
    Moneda item;
    item.respawn();

    PowerUp powerUp;
    powerUp.respawn();
    int timer = 60 * 5;
    int puntos = 0;

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        if (timer > 0) {
            timer--;
        }

        ball.update();

        if (ball.isCollision(item)) {
            item.respawn();
            puntos++;
        }

        if (timer == 0 && ball.isCollision(powerUp)) {
            ball.addVelocity(1);
            timer = 60 * 5;
            powerUp.respawn();
        }

        text.setString("Puntos: "+std::to_string(puntos));

        window.clear();
        window.draw(ball);
        window.draw(item);
        window.draw(text);

        if (timer == 0) {
            window.draw(powerUp);
        }

        window.display();
    }

    return 0;
}




