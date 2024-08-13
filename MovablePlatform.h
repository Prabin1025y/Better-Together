#ifndef MOVABLEPLATFORM_H
#define MOVABLEPLATFORM_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Lever.h"
// #include "LeverControlled.h"
#include "Platform.h"
#include <math.h>
// #include "Animation.h"
// #include "Collider.h"

class MovablePlatform : public Platform
{
protected:
    sf::Vector2f initialPosition;
    sf::Vector2f translatedPosition;

    float speed;

    sf::Vector2f endPosition, startingPosition, currentPosition;

public:
    // MovablePlatform(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position, sf::Vector2f translatedPosition, float speed, sf::IntRect textureRect);
    MovablePlatform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, sf::Vector2f translatedPosition, float speed, sf::IntRect textureRect);
    ~MovablePlatform();

    void OnLeverOn();
    void OnLeverOff();

    void Update(bool isLeverOn, float deltaTime);

    // void OnCollision(sf::Vector2f direction);

    // void keyReleased(sf::Keyboard::Key key);

    // void Update(float deltaTime);

    // bool CheckCollision(Collider &other);

    // Collider getCollider() { return Collider(body); }

    // sf::Vector2f getPosition() { return body.getPosition(); }
};

#endif // MOVABLEPLATFORM_H