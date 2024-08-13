#include "Water.h"

Water::Water(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, sf::Vector2u imageCount, float switchTime) : animation(texture, sf::Vector2u(3, 1), switchTime, true), Collidable(body)
{
    body.setTexture(texture);
    body.setSize(size);
    body.setOrigin(size / 2.0f);
    body.setPosition(position);

    // printf("%d, %d\n", texture->getSize().x, texture->getSize().y);
}

void Water::Update(float deltaTime)
{
    animation.Update(0, deltaTime, 3);

    body.setTextureRect(animation.uvRect);
    // body.setTextureRect(sf::IntRect(0,0,64,32));
}

void Water::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}

Water::~Water() {}