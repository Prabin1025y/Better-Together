#include "Platform.h"

Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, sf::IntRect textureRect)
{
    body.setSize(size);
    body.setOrigin(size / 2.0f);
    body.setPosition(position);
    body.setTexture(texture);
    body.setTextureRect(textureRect);
}

void Platform::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}

Platform::~Platform()
{
}