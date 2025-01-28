#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Inicialización de la ventana
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Ball Dash");

    // Carga de la textura del personaje
    sf::Texture personaje_textura;
    if (!personaje_textura.loadFromFile("BallDashGameImagen.png")) {
        std::cerr << "Error al cargar la textura" << std::endl;
        return -1;
    }

    // Creación del sprite del personaje
    sf::Sprite personaje(personaje_textura);
    float velocity = 2.0f;

    // ajustar tamaño de imagen 
    personaje.setScale(sf::Vector2f(0.1f, 0.1f));
    

    // Game Loop (update del juego)
    while (window.isOpen())
    {
        // Gestión de eventos
        while (auto event = window.pollEvent())
        {
            // Verificar si el evento es de tipo 'Closed'
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        // CMD - Joy

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            personaje.move(sf::Vector2f(0.0f, -velocity));
        } // si quiero que vaya hacia arriba, tengo que restar

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            personaje.move(sf::Vector2f(0.0f, velocity));
        } // si quiero que baje, en realidad tengo que sumar para que el personaje vaya hacia abajo

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
            personaje.move(sf::Vector2f(-velocity, 0.0f));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
            personaje.move(sf::Vector2f(velocity, 0.0f));
        } // movimiento de 5 pixeles hacia la derecha en el eje X y 0 no hay movimiento en el eje Y, por lo que el personaje no sube ni baja

        if (personaje.getPosition().x < 0.0f) {
            personaje.setPosition(sf::Vector2f(0.0f, personaje.getPosition().y));
        }

        if (personaje.getPosition().y < 0.0f) {
            personaje.setPosition(sf::Vector2f(personaje.getPosition().x, 0.0f));
        }

        // Lógica del juego (actualizaciones)

        // Renderizado
        window.clear();
        window.draw(personaje);
        window.display();
    }

    return 0;
}


