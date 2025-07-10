#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "Collisionable.h"
#include <SFML/Graphics.hpp>

class Personaje: public sf:: Drawable, public Collisionable {
private:
    sf::Texture _textura;
    sf::Sprite* _sprite;
    sf::Vector2f _velocity;

public:
    Personaje();
    ~Personaje();
    void update();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;
    void addVelocity(float velocity);
};

// const para indicar que no modifica el estado actual del personaje

#endif // PERSONAJE_H


