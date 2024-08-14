#ifndef WATER_H
#define WATER_H

#include <SFML/Graphics.hpp>
#include "Collidable.h"
#include "AnimationAll.h"
#include "GameManager.h"

class Water : public Collidable
{
protected:
    sf::RectangleShape body;
    // float speed;
    AnimationAll animation;

public:
    Water() : Collidable(body) {}
    Water(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, sf::Vector2u imageCount, float switchTime);
    ~Water();

    void Update(float deltaTime, int row);

    void Draw(sf::RenderWindow& window);

    // Collider getCollider() { return Collider(body); }
};

#endif // WATER_H