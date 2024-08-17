#include "SceneManager.h"
#include "Scene.h"
#include "LevelOne.h"
#include "MainMenu.h"
#include "LevelTwo.h"
#include "GameManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920.0f, 1080.0f), "New WIndow", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);

	//SceneManager sceneManager;
	std::shared_ptr<Scene> levelOne = std::make_shared<MainMenu>(window);
	SceneManager::getInstance().ChangeScene(levelOne);

	sf::Clock clock;

	while (window.isOpen())
	{
		// sf::Event evnt;
		// while (window.pollEvent(evnt))
		// {
		//     if (evnt.type == sf::Event::Closed)
		//         window.close();
		// }
		SceneManager::getInstance().HandleInput(window);

		sf::Time elapsed = clock.restart();
		float deltaTime = elapsed.asSeconds();

		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;
		if (!GameManager::getInstance().getIsGameOver() && !GameManager::getInstance().getIsGamePaused())
			SceneManager::getInstance().Update(deltaTime);
		SceneManager::getInstance().Render(window);
	}

	return 0;
}

// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include <vector>
// #include "Player.h"
// #include "Player2.h"
// #include "Platform.h"
// #include "GameManager.h"
// #include "Enemy.h"
// #include "Lever.h"
// #include "MovablePlatform.h"
// #include "Shuriken.h"
// #include "Water.h"
// #include "Door.h"

// const float VIEW_HEIGHT = 966.0f;
// const float VIEW_WIDTH = 1720.0f;

// void ResizeWindow(const sf::RenderWindow &window, sf::View &view)
// {
//     float aspectRatio = static_cast<float>(window.getSize().x) / static_cast<float>(window.getSize().y);
//     view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
// }

// int main()
// {
//     sf::Texture bgTexture;
//     sf::Texture playerTexture;
//     sf::Texture platformTexture;
//     sf::Texture leverTexture;
//     sf::Texture shurikenTexture;
//     sf::Texture waterTexture;
//     sf::Texture lavaTexture;
//     sf::Texture fanTexture;
//     sf::Texture doortexture;

//     bgTexture.loadFromFile("./images/bg.png");
//     playerTexture.loadFromFile("./images/player_sheet3.png");
//     platformTexture.loadFromFile("./images/tile1.png");
//     leverTexture.loadFromFile("./images/tools.png");
//     shurikenTexture.loadFromFile("./images/Suriken.png");
//     waterTexture.loadFromFile("./images/water.png");
//     lavaTexture.loadFromFile("./images/lava.png");
//     fanTexture.loadFromFile("./images/Fan.png");
//     doortexture.loadFromFile("./images/door.png");

//     sf::Sprite bgSprite;
//     bgSprite.setTexture(bgTexture);
//     bgSprite.setOrigin(bgSprite.getLocalBounds().width / 2.0f, bgSprite.getLocalBounds().height / 2.0f);

//     GameManager &gameManager = GameManager::getInstance();
//     sf::RenderWindow window(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "New WIndow", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);

//     sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT));

//     Player player(&playerTexture, sf::Vector2u(8, 8), 0.15f, 100.0f, 150.0f);
//     Player2 player2(&playerTexture, sf::Vector2u(8, 8), 0.15f, 100.0f, 150.0f);
//     // Enemy enemy(&playerTexture, sf::Vector2u(8, 8), 0.15f, 0.0f);

//     // Platform platform1(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(200.0f, 500.0f));
//     std::vector<Platform> platforms;
//     platforms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(200.0f, 500.0f)));

//     MovablePlatform platformMovable(nullptr, sf::Vector2f(100.0f, 20.0f), sf::Vector2f(200.0f, 100.0f), sf::Vector2f(400.0f, 200.0f), 50.0f);
//     // std::vector<MovablePlatform> movablePlatforms;
//     // movablePlatforms.push_back(platformMovable);
//     // movablePlatforms.push_back(MovablePlatform(nullptr, sf::Vector2f(100.0f, 20.0f), sf::Vector2f(200.0f, 100.0f), sf::Vector2f(400.0f, 200.0f), 50.0f));

//     Lever lever1(&leverTexture);
//     // std::vector<Lever> levers;
//     // levers.push_back(lever1);

//     Door door1(&doortexture, sf::Vector2f(50.0f, 80.0f), sf::Vector2f(500.0f, 200.0f), sf::Vector2u(6, 1), 0.2f);

//     Water lava1(&lavaTexture, sf::Vector2f(160.0f, 60.0f), sf::Vector2f(50.0f, 350.0f), sf::Vector2u(3, 1), 0.3f);
//     Water water1(&waterTexture, sf::Vector2f(100.0f, 40.0f), sf::Vector2f(500.0f, 350.0f), sf::Vector2u(3, 1), 0.1f);
//     Shuriken shuriken1(&shurikenTexture, sf::Vector2f(40.0f, 40.0f), sf::Vector2u(8, 1), 0.1f, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(600.0f, 200.0f), 200.0f);
//     Shuriken fanBlade(&fanTexture, sf::Vector2f(60.0f, 60.0f), sf::Vector2u(8, 1), 0.1f, sf::Vector2f(400.0f, 350.0f), sf::Vector2f(100.0f, 400.0f), 0.0f);

//     float deltaTime = 0.0f;
//     sf::Clock clock;

//     while (window.isOpen())
//     {
//         deltaTime = clock.restart().asSeconds();
//         if (deltaTime > 1.0f / 20.0f)
//             deltaTime = 1.0f / 20.0f;

//         sf::Event evnt;
//         while (window.pollEvent(evnt))
//         {
//             switch (evnt.type)
//             {
//             case sf::Event::Closed:
//                 window.close();
//                 break;

//             case sf::Event::Resized:
//                 ResizeWindow(window, view);
//                 break;
//             case sf::Event::KeyPressed:
//                 gameManager.SetKeyPressed(evnt.key.code);
//                 break;
//                 // case sf::Event::KeyReleased:
//                 //     gameManager.keyReleased(evnt.key.code);
//                 //     break;
//             }
//         }
//         Collider playerCollider = player.getCollider();
//         Collider player2Collider = player2.getCollider();

//         player.Update(deltaTime);
//         player2.Update(deltaTime);
//         platformMovable.Update(lever1, deltaTime);
//         shuriken1.Update(deltaTime);
//         fanBlade.Update(deltaTime);
//         water1.Update(deltaTime);
//         lava1.Update(deltaTime);
//         door1.Update(deltaTime);

//         // movablePlatforms[0].Update(levers[0], deltaTime);
//         // enemy.Update(deltaTime);

//         sf::Vector2f direction;

//         for (int i = 0; i < platforms.size(); i++)
//         {
//             Platform &platform = platforms[i];

//             if (platform.getCollider().CheckCollision(playerCollider, direction, 1.0f))
//                 player.OnCollision(direction);

//             if (platform.getCollider().CheckCollision(player2Collider, direction, 1.0f))
//                 player2.OnCollision(direction);
//         }

//         // if (platform1.getCollider().CheckCollision(playerCollider, direction, 1.0f))
//         // {
//         //     // printf("Colliding with player");
//         //     player.OnCollision(direction);
//         // }

//         // if (platform1.getCollider().CheckCollision(player2Collider, direction, 1.0f))
//         // {
//         //     // printf("Colliding with player");
//         //     player2.OnCollision(direction);
//         // }

//         // for (int i = 0; i < movablePlatforms.size(); i++)
//         // {
//         //     Platform &movablePlatform = movablePlatforms[i];

//         //     if (movablePlatform.getCollider().CheckCollision(playerCollider, direction, 1.0f))
//         //         player.OnCollision(direction);

//         //     if (movablePlatform.getCollider().CheckCollision(player2Collider, direction, 1.0f))
//         //         player2.OnCollision(direction);
//         // }

//         if (platformMovable.getCollider().CheckCollision(player2Collider, direction, 1.0f))
//         {
//             // printf("Colliding with player");
//             player2.OnCollision(direction);
//         }
//         if (platformMovable.getCollider().CheckCollision(playerCollider, direction, 1.0f))
//         {
//             // printf("Colliding with player");
//             player.OnCollision(direction);
//         }

//         if (playerCollider.CheckCollision(player2Collider, direction, 0.5f))
//         {
//             // printf("Colliding with player");
//             if (player2Collider.CheckCollision(playerCollider, direction, 0.5f))
//                 player.OnCollision(direction);
//             else
//                 player2.OnCollision(direction);
//         }

//         if ((lever1.CheckCollision(playerCollider) && gameManager.GetKeyPressed(sf::Keyboard::E)) || ((lever1.CheckCollision(player2Collider) && gameManager.GetKeyPressed(sf::Keyboard::RShift))))
//         {
//             lever1.switchLever();
//         }

//         if (shuriken1.CheckCollision(playerCollider) || shuriken1.CheckCollision(player2Collider))
//         {
//             gameManager.setIsGameOver(true);
//             printf("GameOver");
//         }

//         if (fanBlade.CheckCollision(playerCollider) || fanBlade.CheckCollision(player2Collider))
//         {
//             gameManager.setIsGameOver(true);
//             printf("GameOver");
//         }

//         if (water1.CheckCollision(playerCollider) || lava1.CheckCollision(player2Collider))
//         {
//             gameManager.setIsGameOver(true);
//             printf("GameOver");
//         }

//         if (door1.CheckCollision(playerCollider) || door1.CheckCollision(player2Collider))
//             door1.setIsDoorOpen(true);

//         // Collider enemyCollider = enemy.getCollider();
//         // if (platform1.getCollider().CheckCollision(enemyCollider, direction, 1.0f))
//         // {
//         //     enemy.OnCollision(direction);
//         // }

//         // if (enemyCollider.CheckCollision(playerCollider, direction, 1.0f))
//         // {
//         //     player.OnCollision(direction);
//         // }

//         window.clear(sf::Color(2, 100, 147));

//         bgSprite.setPosition(view.getCenter());

//         window.draw(bgSprite);

//         for (Platform &platform : platforms)
//         {
//             platform.Draw(window);
//         }

//         // for (MovablePlatform &platform : movablePlatforms)
//         // {
//         //     platform.Draw(window);
//         // }
//         platformMovable.Draw(window);
//         water1.Draw(window);
//         lava1.Draw(window);
//         shuriken1.Draw(window);
//         fanBlade.Draw(window);
//         door1.Draw(window);

//         lever1.Draw(window);
//         player.Draw(window);
//         player2.Draw(window);
//         // enemy.Draw(window);

//         view.setCenter(player.getPosition() - sf::Vector2f(0.0f, 250.0f));
//         view.setCenter(player.getPosition().x, 100.0f);
//         window.setView(view);

//         window.display();
//     }
//     return 0;
// }
