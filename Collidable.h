#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include <SFML/Graphics.hpp>
#include "Collider.h"

class Collidable
{
protected:
    sf::RectangleShape& body;

public:
    Collidable(sf::RectangleShape& body);
    ~Collidable();

    bool CheckCollision(Collider& other);

    sf::Vector2f getPosition() { return body.getPosition(); }
    sf::Vector2f getHalfSize() { return (body.getSize() / 2.0f); }
};

#endif // COLLIDABLE_H