#pragma once
#include <SFML/Graphics.hpp>

class GameOverMenu {
private:
	sf::Sprite gameOverText;
	sf::RectangleShape bgCover;
	sf::RectangleShape bg;
	sf::RectangleShape restartButton;
	sf::RectangleShape optionButton;
	sf::RectangleShape exitButton;

public:
	GameOverMenu(sf::RenderWindow& window, sf::Texture* tileTexture);

	sf::RectangleShape getRestartButton() { return restartButton; }
	sf::RectangleShape getOptionButton() { return optionButton; }
	sf::RectangleShape geteExitButton() { return exitButton; }

	void Draw(sf::RenderWindow& window);
};


