#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>

class Personaje: public sf:: Drawable {
private:
    sf::Texture _textura;
    sf::Sprite* _sprite;
    float _velocity;

public:
    Personaje();
    ~Personaje();
    void update();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

// const para indicar que no modifica el estado actual del personaje

#endif // PERSONAJE_H


