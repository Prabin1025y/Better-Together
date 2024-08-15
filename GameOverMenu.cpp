#include "GameOverMenu.h"

GameOverMenu::GameOverMenu(sf::RenderWindow& window, sf::Texture* tileTexture) {


	bgCover.setSize(sf::Vector2f(window.getSize().x * 2, window.getSize().y * 2));
	bgCover.setOrigin(bgCover.getSize() / 2.0f);
	//bgCover.setPosition(sf::Vector2f(233.0f + 35.0f, 44.0f));
	bgCover.setFillColor(sf::Color(0, 0, 0, 200));

	bg.setSize(sf::Vector2f(window.getSize().x / 1.3f, window.getSize().y / 1.3f));
	bg.setOrigin(bg.getSize() / 2.0f);
	//bg.setPosition(sf::Vector2f(233.0f + 35.0f, 44.0f));
	bg.setTexture(tileTexture);
	bg.setTextureRect(sf::IntRect(15 * 16, 10 * 16, 5 * 16, 3 * 16));

	//gameOverText.setPosition(233 - 206.0f, -246.0f);
	gameOverText.setTexture(*tileTexture);
	gameOverText.setScale(2, 2);
	gameOverText.setTextureRect(sf::IntRect(19 * 16, 0, 14 * 16, 7 * 16));

	//restartButton.setPosition(233 - 68.0f, 0);
	restartButton.setTexture(tileTexture);
	restartButton.setTextureRect(sf::IntRect(0, 38 * 16, 2 * 16, 14));
	restartButton.setSize(sf::Vector2f(192.0f, 84.0f));

	//optionButton.setPosition(233 - 68.0f, 96.0f);
	optionButton.setTexture(tileTexture);
	optionButton.setTextureRect(sf::IntRect(0, 39 * 16, 2 * 16, 14));
	optionButton.setSize(sf::Vector2f(192.0f, 84.0f));

	//exitButton.setPosition(233 - 68.0f, 192.0f);
	exitButton.setTexture(tileTexture);
	exitButton.setTextureRect(sf::IntRect(0, 40 * 16, 2 * 16, 14));
	exitButton.setSize(sf::Vector2f(192.0f, 84.0f));



}

void GameOverMenu::Draw(sf::RenderWindow& window, sf::Vector2f cameraPos) {
	bgCover.setPosition(sf::Vector2f(cameraPos.x + 35.0f, 44.0f));
	bg.setPosition(sf::Vector2f(cameraPos.x + 35.0f, 44.0f));
	gameOverText.setPosition(cameraPos.x - 206.0f, -246.0f);
	exitButton.setPosition(cameraPos.x - 68.0f, 192.0f);
	optionButton.setPosition(cameraPos.x - 68.0f, 96.0f);
	restartButton.setPosition(cameraPos.x - 68.0f, 0);

	window.draw(bgCover);
	window.draw(bg);
	window.draw(gameOverText);
	window.draw(restartButton);
	window.draw(optionButton);
	window.draw(exitButton);
	/*window.draw(retryButton);
	window.draw(quitButton);
	window.draw(mainMenuButton);*/
}
