#ifndef SHURIKEN_H
#define SHURIKEN_H

#include <SFML/Graphics.hpp>
#include "Collidable.h"
#include "AnimationAll.h"
#include "Collider.h"
#include "GameManager.h"
#include <math.h>

class Shuriken : public Collidable
{
protected:
    sf::RectangleShape body;
    float speed;
    AnimationAll animation;
    sf::Vector2f endPosition, startingPosition, currentPosition, initialPosition, translatedPosition;

public:
    Shuriken(sf::Texture* texture, sf::Vector2f size, sf::Vector2u imageCount, float switchTime, sf::Vector2f position1, sf::Vector2f position2, float speed);
    ~Shuriken();

    void Update(float deltaTime);

    void Draw(sf::RenderWindow& window);

    // Collider getCollider() { return Collider(body); }
};

#endif // SHURIKEN_H