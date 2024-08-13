#include "Collidable.h"
#include <cmath>

Collidable::Collidable(sf::RectangleShape& body) : body(body)
{
}


bool Collidable::CheckCollision(Collider& other)
{
    sf::Vector2f otherPosition = other.getPosition();
    sf::Vector2f otherHalfSize = other.getHalfSize();
    sf::Vector2f thisPosition = getPosition();
    sf::Vector2f thisHalfSize = getHalfSize();

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    float interSectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float interSectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if (interSectX < 0 && interSectY < 0)
    {
        return true;
    }
    return false;
}
Collidable::~Collidable() {}