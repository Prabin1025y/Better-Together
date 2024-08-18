#include "LevelOne.h"
#include "LevelTwo.h"
#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& window) :
	view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT)),
	window(window),
	playerInput(window, &tileTexture)
{

	GameManager::getInstance().setIsGamePaused(false);
	GameManager::getInstance().setIsGameOver(false);
	bgTexture.loadFromFile("./images/bg_1.png");
	player1Texture.loadFromFile("./images/player1_sheet.png");
	player2Texture.loadFromFile("./images/player2_sheet.png");
	tileTexture.loadFromFile("./images/tiles.png");

	GameData gameData;
	GameManager::getInstance().loadData(gameData);
	std::cout << gameData.bestPlayersLv1;
	std::cout << "Coming";
	std::cout << gameData.player1Name;
	currentPlayer1.setString(gameData.player1Name);
	currentPlayer2.setString(gameData.player2Name);
	level1Best.setString("-");
	level2Best.setString("-");

	if (gameData.player1Name == "Player 1" && gameData.player2Name == "Player 2")
		isPlayerTyping = true;

	if (!(gameData.bestPlayersLv1 == ""))
		level1Best.setString(gameData.bestPlayersLv1);
	if (!(gameData.bestPlayersLv2 == ""))
		level2Best.setString(gameData.bestPlayersLv2);


	font.loadFromFile("Minecraft.ttf");

	currentPlayer1.setFont(font);
	currentPlayer2.setFont(font);
	level1Best.setFont(font);
	level2Best.setFont(font);

	currentPlayer1.setFillColor(sf::Color::Black);
	currentPlayer2.setFillColor(sf::Color::Black);
	level1Best.setFillColor(sf::Color::Black);
	level2Best.setFillColor(sf::Color::Black);

	level1Best.setPosition(-917.0f, -297.0f);
	level2Best.setPosition(-917.0f, -147.0f);

	exitButton.setSize(sf::Vector2f(96.0f * 2, 48.0f * 2));
	exitButton.setTexture(&tileTexture);
	exitButton.setTextureRect(sf::IntRect(0, 40 * 16, 2 * 16, 14));
	exitButton.setPosition(-852.0f, 335.0f);

	nameButton.setSize(sf::Vector2f(96.0f * 2, 48.0f * 2));
	nameButton.setTexture(&tileTexture);
	nameButton.setTextureRect(sf::IntRect(2 * 16, 41 * 16, 2 * 16, 14));
	nameButton.setPosition(650.0f, 335.0f);

	lv1Button.setSize(sf::Vector2f(150.0f, 150.0f));
	lv1Button.setTexture(&tileTexture);
	lv1Button.setTextureRect(sf::IntRect(15 * 16, 14 * 16, 16, 16));
	//lv1Button.setOrigin(lv1Button.getSize() / 2.0f);
	lv1Button.setPosition(-160.0f, 0.0f);

	lv2Button.setSize(sf::Vector2f(150.0f, 150.0f));
	lv2Button.setTexture(&tileTexture);
	//lv2Button.setOrigin(lv2Button.getSize() / 2.0f);
	lv2Button.setTextureRect(sf::IntRect(16 * 16, 14 * 16, 16, 16));
	lv2Button.setPosition(20.0f, 0.0f);

	bg.setTexture(bgTexture);
	bg.setOrigin(bg.getLocalBounds().width / 2.0f, bg.getLocalBounds().height / 2.0f);

	player1.setSize(sf::Vector2f(160, 200));
	player1.setOrigin(player1.getSize() / 2.0f);
	player1.setTexture(&player1Texture);
	player1.setPosition(-409.0f, -352.0f);
	currentPlayer1.setPosition(-856.0f, 256.0f);

	player2.setSize(sf::Vector2f(160, 200));
	player2.setOrigin(player2.getSize() / 2.0f);
	player2.setTexture(&player2Texture);
	player2.setPosition(484.0f, -346.0f);
	currentPlayer2.setPosition(676, 256.0f);

	playerRect = sf::IntRect(0, 5 * 20, 16, 20);

}

//void MainMenu::save() {
//	std::ofstream outF("gameData.dat", std::ios::binary | std::ios::trunc | std::ios::out);
//	outF.write(reinterpret_cast<char*>(&fileData), sizeof(fileData));
//	outF.close();
//}

MainMenu::~MainMenu() {

}


void MainMenu::HandleInput(sf::RenderWindow& window)
{
	std::shared_ptr<Scene> level;
	sf::Event evnt;
	while (window.pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::Closed:
			window.close();
			break;

		case sf::Event::Resized:
			// window.setSize(window.getSize().y )
			// float aspectRatio = static_cast<float>(window.getSize().x) / static_cast<float>(window.getSize().y);
			window.setSize(sf::Vector2u((unsigned int)window.getSize().y * 16 / 9, (unsigned int)window.getSize().y));
			ResizeWindow(window, view);
			break;
		case sf::Event::MouseButtonPressed:
			printf("%d, %d\n", sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
			if (evnt.mouseButton.button == sf::Mouse::Left) {
				sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

				sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

				if (isPlayerTyping) {

					if (playerInput.getTextBox1().getTextBoxBg().getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos)))
						playerInput.getTextBox1().setSelected(true);
					else
						playerInput.getTextBox1().setSelected(false);

					if (playerInput.getTextBox2().getTextBoxBg().getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos)))
						playerInput.getTextBox2().setSelected(true);
					else
						playerInput.getTextBox2().setSelected(false);

					if (playerInput.getRestartButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos)))
					{
						GameData gameData;
						GameManager::getInstance().loadData(gameData);
						std::cout << gameData.bestPlayersLv1;
						//gameData.setPlayerName(playerInput.getTextBox1().getText() == "" ? "Player 1" : playerInput.getTextBox1().getText(), playerInput.getTextBox2().getText() == "" ? "Player 1" : playerInput.getTextBox2().getText());
						gameData.player1Name = playerInput.getTextBox1().getText() == "" ? "Player 1" : playerInput.getTextBox1().getText();
						gameData.player2Name = playerInput.getTextBox2().getText() == "" ? "Player 2" : playerInput.getTextBox2().getText();
						std::cout << gameData.bestPlayersLv1;
						GameManager::getInstance().saveData(gameData);
						currentPlayer1.setString(gameData.player1Name);
						currentPlayer2.setString(gameData.player2Name);
						isPlayerTyping = false;
					}

				}
				else {

					if (exitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos)))
						window.close();

					if (nameButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos)))
						isPlayerTyping = true;

					if (lv1Button.getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos)))
					{
						printf("Level 1");
						level = std::make_shared<LevelOne>(window);
						SceneManager::getInstance().ChangeScene(level);
					}
					else if (lv2Button.getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos)))
					{
						printf("Level 2");
						level = std::make_shared<LevelTwo>(window);
						SceneManager::getInstance().ChangeScene(level);
					}
				}
			}
			break;
		case sf::Event::TextEntered:
			playerInput.getTextBox1().typedOn(evnt);
			playerInput.getTextBox2().typedOn(evnt);
			break;
		}
	}
}

void MainMenu::Update(float deltaTime)
{
	totalTime += deltaTime;
	if (totalTime >= 0.1f) {
		playerRect.left += 16;
		totalTime -= 0.1f;
	}

	if (playerRect.left > 80)
		playerRect.left = 0;

	player1.setTextureRect(playerRect);
	player2.setTextureRect(playerRect);
}

void MainMenu::Render(sf::RenderWindow& window)
{

	window.clear(sf::Color(2, 100, 147));

	bg.setPosition(view.getCenter());


	window.draw(bg);

	window.draw(lv1Button);
	window.draw(lv2Button);

	window.draw(player1);
	window.draw(player2);

	window.draw(level1Best);
	window.draw(level2Best);

	window.draw(exitButton);
	window.draw(nameButton);

	window.draw(currentPlayer1);
	window.draw(currentPlayer2);

	if (isPlayerTyping)
		playerInput.Draw(window, sf::Vector2f(0.0f, 0.0f));

	view.setCenter(0.0f, 0.0f);
	window.setView(view);

	window.display();
}