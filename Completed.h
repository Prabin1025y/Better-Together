#pragma once
#include <SFML/Graphics.hpp>

class Completed {
private:
	sf::Sprite levelCompletedText;
	sf::RectangleShape bgCover;
	sf::RectangleShape bg;
	sf::RectangleShape nextButton;
	sf::RectangleShape optionButton;
	sf::RectangleShape exitButton;
	sf::RectangleShape restartButton;

public:
	Completed(sf::RenderWindow& window, sf::Texture* tileTexture);

	sf::RectangleShape getNextButton() { return nextButton; }
	sf::RectangleShape getOptionButton() { return optionButton; }
	sf::RectangleShape geteExitButton() { return exitButton; }
	sf::RectangleShape getRestartButton() { return restartButton; }

	void Draw(sf::RenderWindow& window, sf::Vector2f cameraPos);
};