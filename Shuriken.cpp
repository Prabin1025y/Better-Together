#include "Shuriken.h"

Shuriken::Shuriken(sf::Texture* texture, sf::Vector2f size, sf::Vector2u imageCount, float switchTime, sf::Vector2f position1, sf::Vector2f position2, float speed) : animation(texture, imageCount, switchTime, true), Collidable(body)
{
    this->speed = speed;
    body.setTexture(texture);
    body.setSize(size);
    body.setOrigin(size / 2.0f);
    body.setPosition(position1);

    initialPosition = body.getPosition();
    translatedPosition = position2;
    currentPosition = initialPosition;

    endPosition = translatedPosition;
    startingPosition = initialPosition;
}

void Shuriken::Update(float deltaTime)
{
    GameManager& gameManager = GameManager::getInstance();

    if (abs(currentPosition.x - endPosition.x) < 2.0f && abs(currentPosition.y - endPosition.y) < 2.0f)
    {
        // printf("switch position");
        endPosition = (endPosition == translatedPosition) ? initialPosition : translatedPosition;
        startingPosition = (startingPosition == initialPosition) ? translatedPosition : initialPosition;
    }

    sf::Vector2f direction = endPosition - startingPosition;
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    sf::Vector2f normalizedDirection = direction / length;

    if ((currentPosition.x < endPosition.x && normalizedDirection.x > 0) ||
        (currentPosition.x > endPosition.x && normalizedDirection.x < 0))
    {
        currentPosition.x += normalizedDirection.x * speed * deltaTime;
    }
    if ((currentPosition.y < endPosition.y && normalizedDirection.y > 0) ||
        (currentPosition.y > endPosition.y && normalizedDirection.y < 0))
    {
        currentPosition.y += normalizedDirection.y * speed * deltaTime;
    }

    animation.Update(0, deltaTime, 8);

    body.setPosition(currentPosition);

    // if (CheckCollision(playerCollider))
    // {
    //     gameManager.setIsGameOver(true);
    // }

    body.setTextureRect(animation.uvRect);
}

void Shuriken::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}

Shuriken::~Shuriken() {}
