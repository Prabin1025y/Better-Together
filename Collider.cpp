#include "Collider.h"

Collider::Collider(sf::RectangleShape& body) : body(body)
{
    // this->body.setSize(sf::Vector2f(16.0f, 20.0f));
}

bool Collider::CheckCollision(Collider& other, sf::Vector2f& direction, float push)
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

        push = std::min(std::max(push, 0.0f), 1.0f); // clamping push between 0 and 1

        if (interSectX > interSectY)
        {
            // push into x direction
            if (deltaX > 0)
            {
                Move(interSectX * (1.0f - push), 0.0f);
                other.Move(-interSectX * push, 0.0f);

                direction.x = 1.0f;
                direction.y = 0.0f;
            }
            else
            {
                Move(-interSectX * (1.0f - push), 0.0f);
                other.Move(interSectX * push, 0.0f);

                direction.x = -1.0f;
                direction.y = 0.0f;
            }
        }
        else
        {
            // push into y direction
            if (deltaY > 0)
            {
                // printf("%d", deltaY);
                Move(0.0f, interSectY * (1.0f - push));
                other.Move(0.0f, -interSectY * push);

                direction.x = 0.0f;
                direction.y = 1.0f;
            }
            else
            {
                Move(0.0f, -interSectY * (1.0f - push));
                other.Move(0.0f, interSectY * push);

                direction.x = 0.0f;
                direction.y = -1.0f;
            }
        }

        return true;
    }

    return false;
}

Collider::~Collider()
{
}