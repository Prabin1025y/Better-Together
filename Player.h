#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "GameManager.h"
// #include "Animation.h"
#include "Collider.h"
#include <math.h>
// #include <cmath>

class Animation;

class Player
{
protected:
    const float gravity = 981.0f;

    sf::RectangleShape body;
    Animation* animation;
    unsigned int row;
    int maxCol;
    float speed;
    bool facingRight;
    bool canPerformAction;

    bool canJump;
    float jumpHeight;
    sf::Vector2f velocity;
    // sf::Event *evnt;
    // bool animationInfinite;

public:
    Player() {}
    Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, sf::Vector2f position);
    ~Player();

    void death();

    bool getCanPerformAction() { return canPerformAction; };
    void setCanPerformAction(bool value);

    void OnCollision(sf::Vector2f direction);

    // void keyReleased(sf::Keyboard::Key key);

    void Update(float deltaTime);

    void Draw(sf::RenderWindow& window);

    Collider getCollider() { return Collider(body); }

    sf::Vector2f getPosition() { return body.getPosition(); }
};

#endif // PLAYER_H