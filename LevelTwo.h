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
#include "Completed.h"
#include "LevelOne.h"
#include "MainMenu.h"

class LevelTwo : public Scene
{
private:
	//SceneManager& sceneManager;

	sf::RectangleShape pauseButton;

	sf::Texture bgTexture;
	sf::Texture player1Texture, player2Texture;
	// sf::Texture platformTexture;
	sf::Texture leverTexture;
	sf::Texture shurikenTexture;
	sf::Texture waterTexture;
	sf::Texture lavaTexture;
	// sf::Texture fanTexture;
	sf::Texture doortexture;
	sf::Texture tiletexture;

	sf::Sprite bgSprite;


	//Sprite grassSprite;


	std::unique_ptr<Player> player1;
	std::unique_ptr<Player2> player2;

	std::unique_ptr<MovablePlatform> movablePlatform1, movablePlatform2, movablePlatform3, movablePlatform4, movablePlatform5;
	std::unique_ptr<Lever> lever1, lever2;
	std::unique_ptr<Door> door1;
	std::unique_ptr<Water> water1, lava1;
	std::unique_ptr<Shuriken> shuriken1, shuriken2, shuriken3, shuriken4, shuriken5, shuriken6;
	// std::unique_ptr<Water> water1;
	// MovablePlatform movablePlatform1;

	sf::View view;
	sf::Vector2f cameraPos;
	sf::RenderWindow& window;

	std::vector<Sprite> sprites;
	std::vector<Platform> platforms;
	std::vector<Platform> nonCollaidablePlatforms;
	//std::vector<Shuriken> shurikens;

	GameOverMenu gameOverMenu;
	PauseMenu pauseMenu;
	Completed completedMenu;




public:
	LevelTwo(sf::RenderWindow& window);

	void HandleInput(sf::RenderWindow& window) override;

	void Update(float deltaTime) override;

	void Render(sf::RenderWindow& window) override;

	void Restart();
};

