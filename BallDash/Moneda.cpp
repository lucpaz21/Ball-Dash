#include "Moneda.h"
#include <stdlib.h>
#include <iostream>

Moneda::Moneda() : _sprite(nullptr)
{
    if (!_textura.loadFromFile("C:/Users/lucia/OneDrive/BallDash/BallDash/moneda.PNG")) {
        std::cerr << "Error: No se pudo cargar la textura 'Moneda.jpg'" << std::endl;
    }
    else {
        _sprite = new sf::Sprite(_textura); // ✅ Ahora se inicializa correctamente
        _sprite->setScale(sf::Vector2f(0.05f, 0.05f));
        _sprite->setPosition(sf::Vector2f(400.0f, 300.0f));
    }
    _sprite->setOrigin(sf::Vector2f::Vector2(_sprite->getGlobalBounds().size.x / 2.0f, _sprite->getGlobalBounds().size.y / 2.0f));
}

void Moneda::update() {

}

void Moneda::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (_sprite) {
        target.draw(*_sprite, states);
    }
}

void Moneda::respawn() {
    _sprite->setPosition(sf::Vector2f(std::rand() % 700 + _sprite->getGlobalBounds().size.x, std::rand() % 500 + _sprite->getGlobalBounds().size.y));
}

sf::FloatRect Moneda::getBounds() const {
    return _sprite->getGlobalBounds();
}