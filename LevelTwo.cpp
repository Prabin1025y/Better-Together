#include "LevelTwo.h"

LevelTwo::LevelTwo(sf::RenderWindow& window) :
	view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT)),
	window(window),
	gameOverMenu(window, &tiletexture),
	pauseMenu(window, &tiletexture)
{
	bgTexture.loadFromFile("./images/lv2_blueprint.png");
	player1Texture.loadFromFile("./images/player1_sheet.png");
	player2Texture.loadFromFile("./images/player2_sheet.png");
	// platformTexture.loadFromFile("./images/tile1.png");
	leverTexture.loadFromFile("./images/tools.png");
	// shurikenTexture.loadFromFile("./images/Suriken.png");
	waterTexture.loadFromFile("./images/lava_water.png");
	//lavaTexture.loadFromFile("./images/lava.png");
	// fanTexture.loadFromFile("./images/Fan.png");
	doortexture.loadFromFile("./images/door.png");
	tiletexture.loadFromFile("./images/tiles.png");

	pauseButton.setSize(sf::Vector2f(48.0f, 48.0f));
	pauseButton.setTexture(&tiletexture);
	pauseButton.setTextureRect(sf::IntRect(2 * 16, 38 * 16, 16, 16));
	pauseButton.setPosition(-686.0f, -399.0f);

	bgSprite.setTexture(bgTexture);
	bgSprite.setOrigin(bgSprite.getLocalBounds().width / 2.0f, bgSprite.getLocalBounds().height / 2.0f);

	//sprites.push_back(Sprite(tiletexture, sf::Vector2f(-292.0f, 292.0f), sf::Vector2f(3, 3), sf::IntRect(15 * 16, 6 * 16, 4 * 16, 2 * 16)));//bottom left stone
	//sprites.push_back(Sprite(tiletexture, sf::Vector2f(-600.0f, 10.0f), sf::Vector2f(2, 2), sf::IntRect(15 * 16, 16, 32, 32))); // top left grass
	//sprites.push_back(Sprite(tiletexture, sf::Vector2f(-444.0f, 244.0f), sf::Vector2f(2, 2), sf::IntRect(15 * 16, 16, 32, 32)));// middle left grass
	//sprites.push_back(Sprite(tiletexture, sf::Vector2f(-328.0f, 323.0f), sf::Vector2f(2, 2), sf::IntRect(15 * 16, 16, 32, 32)));//bottom left grass
	//sprites.push_back(Sprite(tiletexture, sf::Vector2f(348.0f, 305.0f), sf::Vector2f(2, 2), sf::IntRect(15 * 16, 16, 32, 32)));//bottom right grass
	//sprites.push_back(Sprite(tiletexture, sf::Vector2f(960.0f, -366.0f), sf::Vector2f(2, 2), sf::IntRect(15 * 16, 16, 32, 32)));//top right grass
	//sprites.push_back(Sprite(tiletexture, sf::Vector2f(1017.0f, -397.0f), sf::Vector2f(3, 3), sf::IntRect(15 * 16, 6 * 16, 4 * 16, 2 * 16)));//top right stone
	//sprites.push_back(Sprite(tiletexture, sf::Vector2f(-533.0f, -424.0f), sf::Vector2f(3, 3), sf::IntRect(15 * 16, 4 * 16, 2 * 16, 2 * 16)));//trunk
	//sprites.push_back(Sprite(tiletexture, sf::Vector2f(314.0f, 272.0f), sf::Vector2f(3, 3), sf::IntRect(15 * 16, 8 * 16, 2 * 16, 2 * 16)));//grave

	Restart();
	/*player1 = std::make_unique<Player>(&player1Texture, sf::Vector2u(8, 8), 0.15f, 100.0f, 150.0f, sf::Vector2f(-488.0f, -610.0f));
	player2 = std::make_unique<Player2>(&player2Texture, sf::Vector2u(8, 8), 0.15f, 100.0f, 150.0f, sf::Vector2f(-470.0f, 25.0f));

	movablePlatform1 = std::make_unique<MovablePlatform>(&tiletexture, sf::Vector2f(100.0f, 20.0f), sf::Vector2f(-58.0f - 412, 552.0f), sf::Vector2f(-168.0f, 127.0f), 50.0f, sf::IntRect(15 * 16, 0, 2 * 16, 7));

	lever1 = std::make_unique<Lever>(&leverTexture, sf::Vector2f(-228.0f, -334.0f));

	door1 = std::make_unique<Door>(&doortexture, sf::Vector2f(100.0f, 150.0f), sf::Vector2f(993.0f, 165.0f), sf::Vector2u(6, 1), 0.2f);

	water1 = std::make_unique<Water>(&waterTexture, sf::Vector2f(369.0f, 60.0f), sf::Vector2f(626.0f, 377.0f), sf::Vector2u(8, 2), 0.1f);
	lava1 = std::make_unique<Water>(&waterTexture, sf::Vector2f(369.0f, 60.0f), sf::Vector2f(626.0f, 219.0f), sf::Vector2u(8, 2), 0.2f);*/

	// shuriken1 = std::make_unique<Shuriken>(&shurikenTexture, sf::Vector2f(40.0f, 40.0f), sf::Vector2u(8, 1), 0.1f, sf::Vector2f(550.0f, 200.0f), sf::Vector2f(600.0f, 200.0f), 200.0f);
	// fanBlade1 = std::make_unique<Shuriken>(&fanTexture, sf::Vector2f(60.0f, 60.0f), sf::Vector2u(8, 1), 0.1f, sf::Vector2f(400.0f, 350.0f), sf::Vector2f(100.0f, 400.0f), 0.0f);

	platforms.push_back(Platform(&tiletexture, sf::Vector2f(672.0f, 624.0f), sf::Vector2f(-734.0f, 713.0f), sf::IntRect(0, 0, 14 * 16, 13 * 16))); //Left Bottom Big Square
	platforms.push_back(Platform(&tiletexture, sf::Vector2f(672.0f, 624.0f), sf::Vector2f(853.0f, 347.0f), sf::IntRect(0, 0, 14 * 16, 13 * 16))); //middle left platform big square

	//// left middle one tiled
	platforms.push_back(Platform(&tiletexture, sf::Vector2f(434.0f, 62.0f), sf::Vector2f(183.0f, -167.0f), sf::IntRect(0, 14 * 16, 14 * 16, 2 * 16)));
	platforms.push_back(Platform(&tiletexture, sf::Vector2f(434.0f, 62.0f), sf::Vector2f(108.0f, 157.0f), sf::IntRect(0, 14 * 16, 14 * 16, 2 * 16)));
	platforms.push_back(Platform(&tiletexture, sf::Vector2f(672.0f, 96.0f), sf::Vector2f(-724.0f, -180.0f), sf::IntRect(0, 14 * 16, 14 * 16, 2 * 16)));

	platforms.push_back(Platform(&tiletexture, sf::Vector2f(100.0f, 20.0f), sf::Vector2f(-225.0f, -293.0f), sf::IntRect(15 * 16, 0, 2 * 16, 7)));
	//// left top one tiled
	//platforms.push_back(Platform(&tiletexture, sf::Vector2f(672.0f, 96.0f), sf::Vector2f(-672.0f, -280.0f), sf::IntRect(0, 14 * 16, 14 * 16, 2 * 16)));
	//// right top one tiled
	//platforms.push_back(Platform(&tiletexture, sf::Vector2f(672.0f, 96.0f), sf::Vector2f(1232.0f, -254.0f), sf::IntRect(0, 14 * 16, 14 * 16, 2 * 16)));
	//// left wall
	//platforms.push_back(Platform(&tiletexture, sf::Vector2f(672.0f, 22 * 48), sf::Vector2f(-984.0f, 264.0f), sf::IntRect(0, 16 * 16, 14 * 16, 22 * 16)));
	//// right wall
	//platforms.push_back(Platform(&tiletexture, sf::Vector2f(672.0f, 22 * 48), sf::Vector2f(1449.0f, 289.0f), sf::IntRect(0, 16 * 16, 14 * 16, 22 * 16)));
	//// Lava Contained
	//platforms.push_back(Platform(&tiletexture, sf::Vector2f(434.0f, 62.0f), sf::Vector2f(629.0f, 241.0f), sf::IntRect(0, 14 * 16, 14 * 16, 2 * 16)));
}

void LevelTwo::Restart() {
	player1 = std::make_unique<Player>(&player1Texture, sf::Vector2u(8, 8), 0.15f, 100.0f, 150.0f, sf::Vector2f(-488.0f, -610.0f));
	player2 = std::make_unique<Player2>(&player2Texture, sf::Vector2u(8, 8), 0.15f, 100.0f, 150.0f, sf::Vector2f(-470.0f, 25.0f));

	movablePlatform1 = std::make_unique<MovablePlatform>(&tiletexture, sf::Vector2f(100.0f, 20.0f), sf::Vector2f(-470.0f, 552.0f), sf::Vector2f(-168.0f, 127.0f), 50.0f, sf::IntRect(15 * 16, 0, 2 * 16, 7));
	movablePlatform2 = std::make_unique<MovablePlatform>(&tiletexture, sf::Vector2f(100.0f, 20.0f), sf::Vector2f(377.0f, 138.0f), sf::Vector2f(465.0f, 44.0f), 50.0f, sf::IntRect(15 * 16, 0, 2 * 16, 7));

	lever1 = std::make_unique<Lever>(&leverTexture, sf::Vector2f(-228.0f, -334.0f));

	door1 = std::make_unique<Door>(&doortexture, sf::Vector2f(100.0f, 150.0f), sf::Vector2f(993.0f, 165.0f), sf::Vector2u(6, 1), 0.2f);

	water1 = std::make_unique<Water>(&waterTexture, sf::Vector2f(369.0f, 60.0f), sf::Vector2f(176.0f, -188.0f), sf::Vector2u(8, 2), 0.1f);
	lava1 = std::make_unique<Water>(&waterTexture, sf::Vector2f(369.0f, 60.0f), sf::Vector2f(105.0f, 135.0f), sf::Vector2u(8, 2), 0.2f);

	GameManager::getInstance().setIsGameOver(false);
	GameManager::getInstance().setIsGamePaused(false);
}

void LevelTwo::HandleInput(sf::RenderWindow& window)
{

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
		case sf::Event::KeyPressed:
			GameManager::getInstance().SetKeyPressed(evnt.key.code);

			if (evnt.key.code == sf::Keyboard::P)
				GameManager::getInstance().setIsGamePaused(true);


			/*if (evnt.key.code == sf::Keyboard::R)
				Restart();*/
				// printf("Clicked");
				// Collider playerCollider = player1->getCollider();
				// Collider player2Collider = player2->getCollider();
				// if (lever1->CheckCollision(playerCollider) && evnt.key.code == sf::Keyboard::E || ((lever1->CheckCollision(player2Collider) && GameManager::getInstance().GetKeyPressed(sf::Keyboard::RShift))))
				// lever1->switchLever();
			break;
		case sf::Event::MouseButtonPressed:
			printf("%d, %d\n", sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
			if (evnt.mouseButton.button == sf::Mouse::Left) {
				sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

				sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

				if (pauseButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos)))
					GameManager::getInstance().setIsGamePaused(true);

				if (GameManager::getInstance().getIsGameOver()) {
					if (gameOverMenu.getRestartButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos))) {
						printf("Coming");
						Restart();
					}

					if (gameOverMenu.geteExitButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos))) {
						printf("Coming");
						window.close();
					}
				}
				if (GameManager::getInstance().getIsGamePaused()) {
					if (pauseMenu.getRestartButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos))) {
						printf("Coming");
						Restart();
					}

					if (pauseMenu.geteExitButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos))) {
						printf("Coming");
						window.close();
					}

					if (pauseMenu.getResumeButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos))) {
						printf("Coming");
						GameManager::getInstance().setIsGamePaused(false);
					}

				}
			}
			break;
			// case sf::Event::KeyReleased:
			//     gameManager.keyReleased(evnt.key.code);
			//     break;
		}
	}
}

void LevelTwo::Update(float deltaTime)
{

	Collider playerCollider = player1->getCollider();
	Collider player2Collider = player2->getCollider();

	player1->Update(deltaTime);
	player2->Update(deltaTime);
	movablePlatform1->Update(lever1->GetIsOn(), deltaTime);
	movablePlatform2->Update(lever1->GetIsOn(), deltaTime);
	// shuriken1->Update(deltaTime);
	// fanBlade1->Update(deltaTime);
	water1->Update(deltaTime, 1);
	lava1->Update(deltaTime, 0);
	door1->Update(deltaTime);

	// movablePlatforms[0].Update(levers[0], deltaTime);
	// enemy.Update(deltaTime);

	sf::Vector2f direction;

	for (int i = 0; i < platforms.size(); i++)
	{
		Platform& platform = platforms[i];

		if (platform.getCollider().CheckCollision(playerCollider, direction, 1.0f))
			player1->OnCollision(direction);

		if (platform.getCollider().CheckCollision(player2Collider, direction, 1.0f))
			player2->OnCollision(direction);
	}


	// if (platform1.getCollider().CheckCollision(playerCollider, direction, 1.0f))
	// {
	//     // printf("Colliding with player");
	//     player.OnCollision(direction);
	// }

	// if (platform1.getCollider().CheckCollision(player2Collider, direction, 1.0f))
	// {
	//     // printf("Colliding with player");
	//     player2.OnCollision(direction);
	// }

	// for (int i = 0; i < movablePlatforms.size(); i++)
	// {
	//     Platform &movablePlatform = movablePlatforms[i];

	//     if (movablePlatform.getCollider().CheckCollision(playerCollider, direction, 1.0f))
	//         player.OnCollision(direction);

	//     if (movablePlatform.getCollider().CheckCollision(player2Collider, direction, 1.0f))
	//         player2.OnCollision(direction);
	// }

	if (movablePlatform1->getCollider().CheckCollision(player2Collider, direction, 1.0f) || movablePlatform2->getCollider().CheckCollision(player2Collider, direction, 1.0f))
	{
		// printf("Colliding with player");
		player2->OnCollision(direction);
	}
	if (movablePlatform1->getCollider().CheckCollision(playerCollider, direction, 1.0f) || movablePlatform2->getCollider().CheckCollision(playerCollider, direction, 1.0f))
	{
		// printf("Colliding with player");
		player1->OnCollision(direction);
	}

	if (playerCollider.CheckCollision(player2Collider, direction, 0.5f))
	{
		// printf("Colliding with player");
		if (player2Collider.CheckCollision(playerCollider, direction, 0.5f))
			player1->OnCollision(direction);
		else
			player2->OnCollision(direction);
	}

	if (player1->getPosition().y > 1000 || player2->getPosition().y > 1000)
		GameManager::getInstance().setIsGameOver(true);

	// if (lever1->CheckCollision(playerCollider) && GameManager::getInstance().GetKeyPressed(sf::Keyboard::E))
	if ((lever1->CheckCollision(playerCollider) && GameManager::getInstance().GetKeyPressed(sf::Keyboard::S)) || ((lever1->CheckCollision(player2Collider) && GameManager::getInstance().GetKeyPressed(sf::Keyboard::Down))))
	{
		// printf("Touching Player");
		lever1->switchLever();
	}

	// if (shuriken1->CheckCollision(playerCollider) || shuriken1->CheckCollision(player2Collider))
	// {
	//     GameManager::getInstance().setIsGameOver(true);
	//     printf("GameOver");
	// }

	// if (fanBlade1->CheckCollision(playerCollider) || fanBlade1->CheckCollision(player2Collider))
	// {
	//     GameManager::getInstance().setIsGameOver(true);
	//     printf("GameOver");
	// }

	if (water1->CheckCollision(playerCollider))
	{
		//GameManager::getInstance().setIsGameOver(true);
		player1->death();
		printf("GameOver");
	}
	else if (lava1->CheckCollision(player2Collider)) {
		player2->death();
	}

	if (door1->CheckCollision(playerCollider) && door1->CheckCollision(player2Collider))
		door1->setIsDoorOpen(true);

	// Collider enemyCollider = enemy.getCollider();
	// if (platform1.getCollider().CheckCollision(enemyCollider, direction, 1.0f))
	// {
	//     enemy.OnCollision(direction);
	// }

	// if (enemyCollider.CheckCollision(playerCollider, direction, 1.0f))
	// {
	//     player.OnCollision(direction);
	// }
}

void LevelTwo::Render(sf::RenderWindow& window)
{

	window.clear(sf::Color(2, 100, 147));

	bgSprite.setPosition(view.getCenter());

	window.draw(bgSprite);
	//grassSprite.Draw(window);

	for (Platform& platform : platforms)
	{
		platform.Draw(window);
	}

	for (Sprite& sprite : sprites)
	{
		sprite.Draw(window);
	}

	// for (MovablePlatform &platform : movablePlatforms)
	// {
	//     platform.Draw(window);
	// }
	movablePlatform1->Draw(window);
	movablePlatform2->Draw(window);
	water1->Draw(window);
	lava1->Draw(window);
	// shuriken1->Draw(window);
	// fanBlade1->Draw(window);
	door1->Draw(window);

	lever1->Draw(window);
	player1->Draw(window);
	player2->Draw(window);
	// enemy.Draw(window);

	window.draw(pauseButton);

	if (GameManager::getInstance().getIsGameOver())
		gameOverMenu.Draw(window);

	if (GameManager::getInstance().getIsGamePaused())
		pauseMenu.Draw(window);

	// view.setCenter(player1->getPosition() - sf::Vector2f(0.0f, 250.0f));
	view.setCenter(233.0f, 100.0f);
	window.setView(view);

	window.display();
}