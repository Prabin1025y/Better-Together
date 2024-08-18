#include "PlayerNameInput.h"

PlayerNameInput::PlayerNameInput(sf::RenderWindow& window, sf::Texture* tileTexture): 
	textBox1(24, sf::Color::White, false),
	textBox2(24, sf::Color::White, false)
{

	font.loadFromFile("Minecraft.ttf");
	bgCover.setSize(sf::Vector2f(window.getSize().x * 2, window.getSize().y * 2));
	bgCover.setOrigin(bgCover.getSize() / 2.0f);
	//bgCover.setPosition(sf::Vector2f(268.0f, 44.0f));
	bgCover.setFillColor(sf::Color(0, 0, 0, 200));

	bg.setSize(sf::Vector2f(window.getSize().x / 1.3f, window.getSize().y / 1.3f));
	bg.setOrigin(bg.getSize() / 2.0f);
	//bg.setPosition(sf::Vector2f(268.0f, 44.0f));
	bg.setTexture(tileTexture);
	bg.setTextureRect(sf::IntRect(15 * 16, 10 * 16, 5 * 16, 3 * 16));


	nextButton.setPosition(-83.0f, 213.0f);
	nextButton.setTexture(tileTexture);
	nextButton.setTextureRect(sf::IntRect(2 * 16, 39 * 16, 2 * 16, 14));
	nextButton.setSize(sf::Vector2f(192.0f, 84.0f));

	Player1.setString("Player 1 Name:");
	Player1.setFillColor(sf::Color::White);
	Player1.setPosition(-363, -142);
	Player1.setFont(font);

	textBox1.setFont(font);
	textBox1.setPosition(sf::Vector2f(-363, -68));
	textBox1.setLimit(true, 20);
	

	Player2.setString("Player 2 Name:");
	Player2.setFillColor(sf::Color::White);
	Player2.setPosition(138, -142);
	Player2.setFont(font);

	textBox2.setFont(font);
	textBox2.setPosition(sf::Vector2f(138, -68));
	textBox2.setLimit(true, 20);

}

void PlayerNameInput::Draw(sf::RenderWindow& window, sf::Vector2f cameraPos) {
	bgCover.setPosition(sf::Vector2f(cameraPos.x + 35.0f, 44.0f));
	bg.setPosition(sf::Vector2f(cameraPos.x + 35.0f, 44.0f));
	//restartButton.setPosition(cameraPos.x - 68.0f, 46.0f);

	window.draw(bgCover);
	window.draw(bg);
	window.draw(Player1);
	window.draw(Player2);

	textBox1.Draw(window);
	textBox2.Draw(window);

	window.draw(nextButton);
}
