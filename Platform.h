#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>
#include "Collider.h"
#include "GameManager.h"

class Platform
{
protected:
    sf::RectangleShape body;

public:
    Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, sf::IntRect);
    ~Platform();

    void Draw(sf::RenderWindow& window);

    Collider getCollider() { return Collider(body); }
};

#endif // PLATFORM_H