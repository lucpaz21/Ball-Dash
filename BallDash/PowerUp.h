#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class PowerUp: public sf::Drawable, public Collisionable
{
private:
    sf::Texture _textura;
    sf::Sprite* _sprite;

public:
    PowerUp();
    void update();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void respawn();
    sf::FloatRect getBounds() const override; // const al final no me va a modificar el estado del objeto 
};

