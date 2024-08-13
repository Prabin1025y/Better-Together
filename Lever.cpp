#include "Lever.h"
#include "GameManager.h"
#include <cmath>

Lever::Lever(sf::Texture* texture, sf::Vector2f position) : Collidable(body)
{
    body.setSize(sf::Vector2f(60.0f, 60.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(position);
    body.setTexture(texture);

    uvRect.left = 0;
    uvRect.top = 0;
    uvRect.width = 16;
    uvRect.height = 16;

    isOn = false;

    body.setTextureRect(uvRect);
}

void Lever::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}

void Lever::switchLever()
{

    isOn = !isOn;
    if (isOn)
    {
        uvRect.top = 16;
    }
    else
    {
        uvRect.top = 0;
    }
    body.setTextureRect(uvRect);
}

// bool Lever::CheckCollision(Collider &other)
// {
//     sf::Vector2f otherPosition = other.getPosition();
//     sf::Vector2f otherHalfSize = other.getHalfSize();
//     sf::Vector2f thisPosition = body.getPosition();
//     sf::Vector2f thisHalfSize = body.getSize() / 2.0f;

//     float deltaX = otherPosition.x - thisPosition.x;
//     float deltaY = otherPosition.y - thisPosition.y;

//     float interSectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
//     float interSectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

//     if (interSectX < 0 && interSectY < 0)
//     {
//         return true;
//     }
//     return false;
// }
Lever::~Lever() {}