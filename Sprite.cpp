#include "Sprite.h"

Sprite::Sprite(sf::Texture &texture, sf::Vector2f position, sf::Vector2f size, sf::IntRect textureRect) {
	sprite.setPosition(position);
	sprite.setTexture(texture);
	sprite.setScale(size);
	sprite.setTextureRect(textureRect);
}

void Sprite::Draw(sf::RenderWindow &window) {
	window.draw(sprite);
}

Sprite::~Sprite(){}