#pragma once
#include <SFML/Graphics.hpp>
#include "TextBox.h"

class PlayerNameInput {
private:
	sf::Text Player1, Player2;
	sf::RectangleShape bgCover;
	sf::RectangleShape bg;
	sf::RectangleShape restartButton;
	Textbox textBox1, textBox2;

	sf::Font font;

public:
	PlayerNameInput(sf::RenderWindow& window, sf::Texture* tileTexture);

	sf::RectangleShape getRestartButton() { return restartButton; }

	void Draw(sf::RenderWindow& window, sf::Vector2f cameraPos);


	Textbox& getTextBox1() { return textBox1; }
	Textbox& getTextBox2() { return textBox2; }
};