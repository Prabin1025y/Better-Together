#include "PauseMenu.h"

PauseMenu::PauseMenu(sf::RenderWindow& window, sf::Texture* tileTexture) {


	bgCover.setSize(sf::Vector2f(window.getSize().x * 2, window.getSize().y * 2));
	bgCover.setOrigin(bgCover.getSize() / 2.0f);
	//bgCover.setPosition(sf::Vector2f(268.0f, 44.0f));
	bgCover.setFillColor(sf::Color(0, 0, 0, 200));

	bg.setSize(sf::Vector2f(window.getSize().x / 1.3f, window.getSize().y / 1.3f));
	bg.setOrigin(bg.getSize() / 2.0f);
	//bg.setPosition(sf::Vector2f(268.0f, 44.0f));
	bg.setTexture(tileTexture);
	bg.setTextureRect(sf::IntRect(15 * 16, 10 * 16, 5 * 16, 3 * 16));

	//pauseText.setPosition(-69.0f, -246.0f);
	pauseText.setTexture(*tileTexture);
	pauseText.setScale(2, 2);
	pauseText.setTextureRect(sf::IntRect(34 * 16, 0, 20 * 16, 4 * 16));

	//resumeButton.setPosition(165.0f, -50.0f);
	resumeButton.setTexture(tileTexture);
	resumeButton.setTextureRect(sf::IntRect(0, 41 * 16, 2 * 16, 14));
	resumeButton.setSize(sf::Vector2f(192.0f, 84.0f));

	//restartButton.setPosition(165.0f, 46.0f);
	restartButton.setTexture(tileTexture);
	restartButton.setTextureRect(sf::IntRect(0, 38 * 16, 2 * 16, 14));
	restartButton.setSize(sf::Vector2f(192.0f, 84.0f));

	//optionButton.setPosition(165.0f, 142.0f);
	optionButton.setTexture(tileTexture);
	optionButton.setTextureRect(sf::IntRect(0, 39 * 16, 2 * 16, 14));
	optionButton.setSize(sf::Vector2f(192.0f, 84.0f));

	//exitButton.setPosition(165.0f, 238.0f);
	exitButton.setTexture(tileTexture);
	exitButton.setTextureRect(sf::IntRect(0, 40 * 16, 2 * 16, 14));
	exitButton.setSize(sf::Vector2f(192.0f, 84.0f));


}

void PauseMenu::Draw(sf::RenderWindow& window, sf::Vector2f cameraPos) {
	bgCover.setPosition(sf::Vector2f(cameraPos.x + 35.0f, 44.0f));
	bg.setPosition(sf::Vector2f(cameraPos.x + 35.0f, 44.0f));
	pauseText.setPosition(cameraPos.x - 302.0f, -246.0f);
	resumeButton.setPosition(cameraPos.x - 68.0f, -50.0f);
	exitButton.setPosition(cameraPos.x - 68.0f, 238.0f);
	optionButton.setPosition(cameraPos.x - 68.0f, 142.0f);
	restartButton.setPosition(cameraPos.x - 68.0f, 46.0f);

	window.draw(bgCover);
	window.draw(bg);
	window.draw(pauseText);
	window.draw(resumeButton);
	window.draw(restartButton);
	window.draw(optionButton);
	window.draw(exitButton);
}
