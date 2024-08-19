#include "Player2.h"
#include "Animation.h"

Player2::Player2(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, sf::Vector2f position) : Player(texture, imageCount, switchTime, speed, jumpHeight, position)
{
}

void Player2::Update(float deltaTime)
{
    // sf::Vector2f movement(0.0f, 0.0f);
    // GameManager &gameManager = GameManager::getInstance();
    velocity.x = 0.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        velocity.x -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        velocity.x += speed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && canJump)
    {
        GameManager::getInstance().playSound("jump1.wav");
        canJump = false;
        velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
    }

    velocity.y += gravity * deltaTime;

    if (velocity.x > 0)
        facingRight = true;
    else if (velocity.x < 0)
        facingRight = false;

    // printf("%d , %d \n",velocity.x, velocity.y);
    if (canPerformAction)
    {
        if (velocity.y < 0.0f)
        {
            maxCol = 1;
            row = 2;
        }
        else if (!canJump)
        {
            maxCol = 1;
            row = 3;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            canPerformAction = false;
            row = 4;
            maxCol = 6;
            animation->setCurrentImageX(0);
            printf("\nPunch");
        }
        else if (velocity.x == 0.0f)
        {
            row = 0;
            maxCol = 6;
        }
        else
        {
            row = 1;
            maxCol = 6;
        }
    }

    animation->Update(row, deltaTime, maxCol, facingRight, this);
    body.setTextureRect(animation->uvRect);
    body.move(velocity * deltaTime);
}