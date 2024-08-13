#ifndef PLAYER2_H
#define PLAYER2_H

// #include <SFML/Graphics.hpp>
// #include "Animation.h"
// #include "Collider.h"
#include "Player.h"
// #include <cmath>

class Player2 : public Player
{
private:
    // sf::RectangleShape body;
    // Animation animation;
    // unsigned int row;
    // int maxCol;
    // float speed;
    // bool facingRight;

    // bool canJump;
    // float jumpHeight;
    // sf::Vector2f velocity;
    // sf::Event *evnt;
    // bool animationInfinite;

public:
    Player2() {}
    Player2(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, sf::Vector2f position);
    // ~Player2();

    // void OnCollision(sf::Vector2f direction);

    // // void keyReleased(sf::Keyboard::Key key);

    void Update(float deltaTime);

    // void Draw(sf::RenderWindow &window);

    // Collider getCollider() { return Collider(body); }

    // sf::Vector2f getPosition() { return body.getPosition(); }
};

#endif // PLAYER2_H