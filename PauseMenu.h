#pragma once
#include <SFML/Graphics.hpp>

class PauseMenu {
private:
	sf::Sprite pauseText;
	sf::RectangleShape bgCover;
	sf::RectangleShape bg;
	sf::RectangleShape resumeButton;
	sf::RectangleShape optionButton;
	sf::RectangleShape exitButton;
	sf::RectangleShape restartButton;

public:
	PauseMenu(sf::RenderWindow& window, sf::Texture* tileTexture);

	sf::RectangleShape getResumeButton() { return resumeButton; }
	sf::RectangleShape getOptionButton() { return optionButton; }
	sf::RectangleShape geteExitButton() { return exitButton; }
	sf::RectangleShape getRestartButton() { return restartButton; }

	void Draw(sf::RenderWindow& window, sf::Vector2f cameraPos);
};