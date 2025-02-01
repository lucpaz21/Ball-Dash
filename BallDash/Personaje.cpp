#include "Personaje.h"
#include <iostream>

Personaje::Personaje() : _velocity(4.0f), _sprite(nullptr)
{
    if (!_textura.loadFromFile("C:/Users/lucia/OneDrive/BallDash/BallDash/BallDashGameImagen.png")) {
        std::cerr << "Error: No se pudo cargar la textura 'BallDashGameImagen.png'" << std::endl;
    }
    else {
        _sprite = new sf::Sprite(_textura); // ✅ Ahora se inicializa correctamente
        _sprite->setScale(sf::Vector2f(0.1f, 0.1f));
        _sprite->setPosition(sf::Vector2f(400.0f, 300.0f));
    }
}

Personaje::~Personaje() {
    delete _sprite; // ✅ Liberamos memoria para evitar fugas
}

void Personaje::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        _sprite->move(sf::Vector2f(0.0f, -_velocity));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        _sprite->move(sf::Vector2f(0.0f, _velocity));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        _sprite->move(sf::Vector2f(-_velocity, 0.0f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        _sprite->move(sf::Vector2f(_velocity, 0.0f));
    }

    // Restricciones de movimiento dentro de la ventana (800x600)
    if (_sprite->getPosition().x < 0.0f) {
        _sprite->setPosition(sf::Vector2f(0.0f, _sprite->getPosition().y));
    }
    if (_sprite->getPosition().y < 0.0f) {
        _sprite->setPosition(sf::Vector2f(_sprite->getPosition().x, 0.0f));
    }

    sf::FloatRect bounds = _sprite->getGlobalBounds();
    sf::Vector2f size = bounds.size;

    if (_sprite->getPosition().x + size.x > 800) {
        _sprite->setPosition(sf::Vector2f(800 - size.x, _sprite->getPosition().y));
    }
    if (_sprite->getPosition().y + size.y > 600) {
        _sprite->setPosition(sf::Vector2f(_sprite->getPosition().x, 600 - size.y));
    }
}

void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (_sprite) {
        target.draw(*_sprite, states);
    }
}
