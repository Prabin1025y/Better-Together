#ifndef COLLIDER_H
#define COLLIDER_H

#include <SFML/Graphics.hpp>

class Collider
{
private:
    sf::RectangleShape& body;

public:
    Collider(sf::RectangleShape& body);
    ~Collider();

    void Move(float dx, float dy) { body.move(dx, dy); }

    bool CheckCollision(Collider& other, sf::Vector2f& direction, float push);

    sf::Vector2f getPosition() { return body.getPosition(); }
    sf::Vector2f getHalfSize() { return (body.getSize() / 2.0f); }
};

#endif // COLLIDER_H