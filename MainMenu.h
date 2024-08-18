#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "AnimationAll.h"
#include "GameManager.h"
#include "TextBox.h"
#include "PlayerNameInput.h"
class MainMenu : public Scene
{
private:
	sf::RectangleShape player1, player2, exitButton, nameButton, lv1Button, lv2Button;

	sf::Texture tileTexture, bgTexture, player1Texture, player2Texture;
	AnimationAll animation;
	sf::IntRect playerRect;
	sf::Sprite bg;
	sf::View view;
	sf::RenderWindow& window;
	float totalTime = 0.0f;

	bool isPlayerTyping = false;

	//FileData fileData;

	sf::Text currentPlayer1, currentPlayer2, level1Best, level2Best;

	sf::Font font;
	PlayerNameInput playerInput;

public:
	MainMenu(sf::RenderWindow& window);

	void HandleInput(sf::RenderWindow& window) override;

	void Update(float deltaTime) override;

	void Render(sf::RenderWindow& window) override;

	//void save();

	~MainMenu();

};

