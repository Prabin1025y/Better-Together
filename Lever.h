#ifndef LEVER_H
#define LEVER_H

#include <SFML/Graphics.hpp>
#include "Collidable.h"
// #include "Animation.h"
// #include "Collider.h"

class Lever : public Collidable
{
private:
    sf::RectangleShape body;
    bool isOn;

public:
    sf::IntRect uvRect;

public:
    Lever(sf::Texture* texture, sf::Vector2f position);
    ~Lever();

    void switchLever();

    bool GetIsOn() { return isOn; }

    // void OnCollision(sf::Vector2f direction);

    // void keyReleased(sf::Keyboard::Key key);

    // void Update(float deltaTime);

    // bool CheckCollision(Collider &other);

    void Draw(sf::RenderWindow& window);

    // Collider getCollider() { return Collider(body); }

    // sf::Vector2f getPosition() { return body.getPosition(); }
};

#endif // LEVER_H