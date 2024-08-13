#include "MovablePlatform.h"

MovablePlatform::MovablePlatform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, sf::Vector2f translatedPosition, float speed, sf::IntRect textureRect)
    : Platform(texture, size, position, textureRect)
    // : Platform(texture, size, position,textureRect)
{
    initialPosition = body.getPosition();

    currentPosition = initialPosition;

    this->translatedPosition = translatedPosition;
    this->speed = speed;
}

void MovablePlatform::OnLeverOn()
{
    endPosition = translatedPosition;
    startingPosition = initialPosition;
    // body.move()
    // body.setPosition(translatedPosition);
}
void MovablePlatform::OnLeverOff()
{
    endPosition = initialPosition;
    startingPosition = translatedPosition;
    // body.setPosition(initialPosition);
}

void MovablePlatform::Update(bool isLeverOn, float deltaTime)
{
    // std::cout << lever.GetIsOn() << std::endl;
    if (isLeverOn)
        OnLeverOn();
    else
        OnLeverOff();

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

    body.setPosition(currentPosition);
}

MovablePlatform::~MovablePlatform() {}