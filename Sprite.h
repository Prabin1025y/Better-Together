#pragma once
#include<SFML/Graphics.hpp>


class Sprite
{
private:
	sf::Sprite sprite;

public:
	Sprite(sf::Texture& texture, sf::Vector2f position, sf::Vector2f size, sf::IntRect textureRect);
	~Sprite();

	void Draw(sf::RenderWindow& window);


};

