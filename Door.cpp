#include "Door.h"

Door::Door(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, sf::Vector2u imageCount, float switchTime) : Collidable(body), animation(texture, imageCount, switchTime, false)
{
    body.setPosition(position);
    body.setTexture(texture);
    body.setSize(size);
    isDoorOpen = false;
}

void Door::setIsDoorOpen(bool value)
{
    isDoorOpen = value;
}

void Door::Update(float deltaTime)
{
    if (isDoorOpen)
        animation.Update(0, deltaTime, 6);

    body.setTextureRect(animation.uvRect);
}

void Door::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}

Door::~Door() {}