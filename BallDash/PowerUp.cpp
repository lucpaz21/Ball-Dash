#include "PowerUp.h"
#include <stdlib.h>
#include <iostream>

PowerUp::PowerUp() : _sprite(nullptr)
{
    if (!_textura.loadFromFile("C:/Users/lucia/OneDrive/BallDash/BallDash/imagenPelota.PNG")) {
        std::cerr << "Error: No se pudo cargar la textura 'objetovelocidad.jpg'" << std::endl;
    }
    else {
        _sprite = new sf::Sprite(_textura); // ? Ahora se inicializa correctamente
        _sprite->setScale(sf::Vector2f(0.15f, 0.15f));
        _sprite->setPosition(sf::Vector2f(400.0f, 300.0f));
    }
    _sprite->setOrigin(sf::Vector2f::Vector2(_sprite->getGlobalBounds().size.x / 2.0f, _sprite->getGlobalBounds().size.y / 2.0f));
}

void PowerUp::update() {

}

void PowerUp::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (_sprite) {
        target.draw(*_sprite, states);
    }
}

void PowerUp::respawn() {
    //_sprite->setPosition(sf::Vector2f(std::rand() % 700 + _sprite->getGlobalBounds().size.x, std::rand() % 500 + _sprite->getGlobalBounds().size.y));
    if (_sprite) {
        float x = static_cast<float>(std::rand() % (800 - static_cast<int>(_sprite->getGlobalBounds().size.x)) + _sprite->getGlobalBounds().size.x / 2.0f);
        float y = static_cast<float>(std::rand() % (600 - static_cast<int>(_sprite->getGlobalBounds().size.y)) + _sprite->getGlobalBounds().size.y / 2.0f);
        _sprite->setPosition(sf::Vector2f(x, y));
    }
}

sf::FloatRect PowerUp::getBounds() const {
    return _sprite->getGlobalBounds();
}
