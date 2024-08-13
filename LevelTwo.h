#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "Scene.h"
#include "SceneManager.h"
#include "Player.h"
#include "Player2.h"
#include "Water.h"
#include "Platform.h"
#include "MovablePlatform.h"
#include "Lever.h"
#include "Door.h"
#include "Shuriken.h"
#include "Sprite.h"
#include "GameOverMenu.h"
#include "PauseMenu.h"

class LevelTwo : public Scene
{
private:
	//SceneManager& sceneManager;

	sf::RectangleShape pauseButton;

	sf::Texture bgTexture;
	sf::Texture player1Texture, player2Texture;
	// sf::Texture platformTexture;
	sf::Texture leverTexture;
	// sf::Texture shurikenTexture;
	sf::Texture waterTexture;
	sf::Texture lavaTexture;
	// sf::Texture fanTexture;
	sf::Texture doortexture;
	sf::Texture tiletexture;

	sf::Sprite bgSprite;


	//Sprite grassSprite;


	std::unique_ptr<Player> player1;
	std::unique_ptr<Player2> player2;

	std::unique_ptr<MovablePlatform> movablePlatform1;
	std::unique_ptr<Lever> lever1;
	std::unique_ptr<Door> door1;
	std::unique_ptr<Water> water1, lava1;
	// std::unique_ptr<Shuriken> shuriken1, fanBlade1;
	// std::unique_ptr<Water> water1;
	// MovablePlatform movablePlatform1;

	sf::View view;
	sf::RenderWindow& window;

	std::vector<Sprite> sprites;
	std::vector<Platform> platforms;

	GameOverMenu gameOverMenu;
	PauseMenu pauseMenu;



public:
	LevelTwo(sf::RenderWindow& window);

	void HandleInput(sf::RenderWindow& window) override;

	void Update(float deltaTime) override;

	void Render(sf::RenderWindow& window) override;

	void Restart();
};

