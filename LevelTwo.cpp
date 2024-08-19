#include "LevelTwo.h"

LevelTwo::LevelTwo(sf::RenderWindow& window) :
	view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT)),
	window(window),
	gameOverMenu(window, &tiletexture),
	pauseMenu(window, &tiletexture),
	completedMenu(window, &tiletexture)
{

	//bgTexture.loadFromFile("./images/lv2_blueprint.png");
	//bgTexture.loadFromFile("./images/bg.png");
	bgTexture.loadFromFile("./images/bg1.jpeg");
	player1Texture.loadFromFile("./images/player1_sheet.png");
	player2Texture.loadFromFile("./images/player2_sheet.png");
	// platformTexture.loadFromFile("./images/tile1.png");
	leverTexture.loadFromFile("./images/tools.png");
	shurikenTexture.loadFromFile("./images/Suriken.png");
	waterTexture.loadFromFile("./images/lava_water.png");
	//lavaTexture.loadFromFile("./images/lava.png");
	// fanTexture.loadFromFile("./images/Fan.png");
	doortexture.loadFromFile("./images/door.png");
	tiletexture.loadFromFile("./images/tiles.png");
	minecraftFont.loadFromFile("Minecraft.ttf");

	timeText.setFont(minecraftFont);
	timeText.setFillColor(sf::Color::Red);
	timeText.setStyle(sf::Text::Bold);
	timeText.setOutlineColor(sf::Color::Black);
	timeText.setOutlineThickness(1);

	pauseButton.setSize(sf::Vector2f(60.0f, 60.0f));
	pauseButton.setTexture(&tiletexture);
	pauseButton.setTextureRect(sf::IntRect(2 * 16, 38 * 16, 16, 16));


	bgSprite.setTexture(bgTexture);
	bgSprite.setOrigin(bgSprite.getLocalBounds().width / 2.0f, bgSprite.getLocalBounds().height / 2.0f);

	GameManager::getInstance().changeSong("level2Music.wav", true);

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

	/*shurikens.push_back(Shuriken(&shurikenTexture, sf::Vector2f(40.0f, 40.0f), sf::Vector2u(8, 1), 0.1f, sf::Vector2f(692.0f, 1.0f), sf::Vector2f(692.0f, -227.0f), 300.0f));
	shurikens.push_back(Shuriken(&shurikenTexture, sf::Vector2f(40.0f, 40.0f), sf::Vector2u(8, 1), 0.1f, sf::Vector2f(842.0f, -227.0f), sf::Vector2f(842.0f, 1.0f), 300.0f));
	shurikens.push_back(Shuriken(&shurikenTexture, sf::Vector2f(40.0f, 40.0f), sf::Vector2u(8, 1), 0.1f, sf::Vector2f(992.0f, 1.0f), sf::Vector2f(992.0f, -227.0f), 300.0f));

	shurikens.push_back(Shuriken(&shurikenTexture, sf::Vector2f(40.0f, 40.0f), sf::Vector2u(8, 1), 0.1f, sf::Vector2f(1435.0f, 102.0f), sf::Vector2f(1643.0f, 102.0f), 300.0f));*/


	shuriken1 = std::make_unique<Shuriken>(&shurikenTexture, sf::Vector2f(40.0f, 40.0f), sf::Vector2u(8, 1), 0.1f, sf::Vector2f(692.0f, 1.0f), sf::Vector2f(692.0f, -227.0f), 300.0f);
	shuriken2 = std::make_unique<Shuriken>(&shurikenTexture, sf::Vector2f(40.0f, 40.0f), sf::Vector2u(8, 1), 0.1f, sf::Vector2f(842.0f, -227.0f), sf::Vector2f(842.0f, 1.0f), 300.0f);
	shuriken3 = std::make_unique<Shuriken>(&shurikenTexture, sf::Vector2f(40.0f, 40.0f), sf::Vector2u(8, 1), 0.1f, sf::Vector2f(992.0f, 1.0f), sf::Vector2f(992.0f, -227.0f), 300.0f);

	shuriken4 = std::make_unique<Shuriken>(&shurikenTexture, sf::Vector2f(40.0f, 40.0f), sf::Vector2u(8, 1), 0.1f, sf::Vector2f(1435.0f, 102.0f), sf::Vector2f(1643.0f, 102.0f), 200.0f);
	shuriken5 = std::make_unique<Shuriken>(&shurikenTexture, sf::Vector2f(40.0f, 40.0f), sf::Vector2u(8, 1), 0.1f, sf::Vector2f(1946.0f, 102.0f), sf::Vector2f(2154.0f, 102.0f), 200.0f);
	shuriken6 = std::make_unique<Shuriken>(&shurikenTexture, sf::Vector2f(40.0f, 40.0f), sf::Vector2u(8, 1), 0.1f, sf::Vector2f(1792.0f, 226.0f), sf::Vector2f(1792.0f, 78.0f), 300.0f);

	platforms.push_back(Platform(&tiletexture, sf::Vector2f(672.0f, 96.0f), sf::Vector2f(-724.0f, -180.0f), sf::IntRect(0, 14 * 16, 14 * 16, 2 * 16))); // Left top one tiled 

	// fanBlade1 = std::make_unique<Shuriken>(&fanTexture, sf::Vector2f(60.0f, 60.0f), sf::Vector2u(8, 1), 0.1f, sf::Vector2f(400.0f, 350.0f), sf::Vector2f(100.0f, 400.0f), 0.0f);
	platforms.push_back(Platform(&tiletexture, sf::Vector2f(100.0f, 20.0f), sf::Vector2f(-225.0f, -293.0f), sf::IntRect(15 * 16, 0, 2 * 16, 7)));//Lever Container left

	platforms.push_back(Platform(&tiletexture, sf::Vector2f(672.0f, 624.0f), sf::Vector2f(-734.0f, 713.0f), sf::IntRect(0, 0, 14 * 16, 13 * 16))); //Left Bottom Big Square
	platforms.push_back(Platform(&tiletexture, sf::Vector2f(672.0f, 624.0f), sf::Vector2f(853.0f, 347.0f), sf::IntRect(0, 0, 14 * 16, 13 * 16))); //middle left platform big square
	platforms.push_back(Platform(&tiletexture, sf::Vector2f(672.0f, 22 * 48), sf::Vector2f(-984.0f, 70.0f), sf::IntRect(0, 16 * 16, 14 * 16, 22 * 16))); //left wall

	platforms.push_back(Platform(&tiletexture, sf::Vector2f(240.0f, 864.0f), sf::Vector2f(2411.0f, 264.0f), sf::IntRect(0, 42 * 16, 6 * 16, 18 * 16))); //right thin big platform

	nonCollaidablePlatforms.push_back(Platform(&tiletexture, sf::Vector2f(434.0f, 62.0f), sf::Vector2f(183.0f, -167.0f), sf::IntRect(0, 14 * 16, 14 * 16, 2 * 16))); //Water Container left
	nonCollaidablePlatforms.push_back(Platform(&tiletexture, sf::Vector2f(434.0f, 62.0f), sf::Vector2f(108.0f, 157.0f), sf::IntRect(0, 14 * 16, 14 * 16, 2 * 16))); //Lava Container Left


	platforms.push_back(Platform(&tiletexture, sf::Vector2f(434.0f, 62.0f), sf::Vector2f(1544.0f, 161.0f), sf::IntRect(0, 14 * 16, 14 * 16, 2 * 16))); //shuriken container 1
	platforms.push_back(Platform(&tiletexture, sf::Vector2f(434.0f, 62.0f), sf::Vector2f(2055.0f, 161.0f), sf::IntRect(0, 14 * 16, 14 * 16, 2 * 16))); //shuriken container 2

	//platforms.push_back(Platform(&tiletexture, sf::Vector2f(434.0f, 62.0f), sf::Vector2f(2764.0f, 161.0f), sf::IntRect(0, 14 * 16, 14 * 16, 2 * 16))); //right most movable

	//Invisible Platforms for water
	platforms.push_back(Platform(&tiletexture, sf::Vector2f(25.0f, 62.0f), sf::Vector2f(430.0f - 521.0f, 241.0f - 85.0f), sf::IntRect(0, 0, 0, 0)));
	platforms.push_back(Platform(&tiletexture, sf::Vector2f(34.0f, 59.0f), sf::Vector2f(827.0f - 521.0f, 240.0f - 85.0f), sf::IntRect(0, 0, 0, 0)));
	platforms.push_back(Platform(&tiletexture, sf::Vector2f(376.0f, 39.0f), sf::Vector2f(621.0f - 521.0f, 250.0f - 85.0f), sf::IntRect(0, 0, 0, 0)));

	//Invisible Platforms for lava
	platforms.push_back(Platform(&tiletexture, sf::Vector2f(25.0f, 62.0f), sf::Vector2f(430.0f - 521.0f + 71, 241.0f - 85.0f - 324), sf::IntRect(0, 0, 0, 0)));
	platforms.push_back(Platform(&tiletexture, sf::Vector2f(34.0f, 59.0f), sf::Vector2f(827.0f - 521.0f + 71, 240.0f - 85.0f - 324), sf::IntRect(0, 0, 0, 0)));
	platforms.push_back(Platform(&tiletexture, sf::Vector2f(376.0f, 39.0f), sf::Vector2f(621.0f - 521.0f + 71, 250.0f - 85.0f - 324), sf::IntRect(0, 0, 0, 0)));
}

void LevelTwo::Restart() {
	GameManager::getInstance().track1.play();
	time = 0.0f;
	cameraPos = sf::Vector2f(233.0f, 100.0f);
	/*player1 = std::make_unique<Player>(&player1Texture, sf::Vector2u(8, 8), 0.15f, 100.0f, 150.0f, sf::Vector2f(2290.0f, -227.0f));
	player2 = std::make_unique<Player2>(&player2Texture, sf::Vector2u(8, 8), 0.15f, 100.0f, 150.0f, sf::Vector2f(2517.0f, -227.0f));*/

	player1 = std::make_unique<Player>(&player1Texture, sf::Vector2u(8, 8), 0.15f, 100.0f, 150.0f, sf::Vector2f(-511.0f, -303.0f));
	player2 = std::make_unique<Player2>(&player2Texture, sf::Vector2u(8, 8), 0.15f, 100.0f, 150.0f, sf::Vector2f(-470.0f, 25.0f));

	movablePlatform1 = std::make_unique<MovablePlatform>(&tiletexture, sf::Vector2f(100.0f, 20.0f), sf::Vector2f(-470.0f, 552.0f), sf::Vector2f(-168.0f, 127.0f), 50.0f, sf::IntRect(15 * 16, 0, 2 * 16, 7));
	movablePlatform2 = std::make_unique<MovablePlatform>(&tiletexture, sf::Vector2f(100.0f, 20.0f), sf::Vector2f(465.0f, 44.0f), sf::Vector2f(465.0f, 507.0f), 50.0f, sf::IntRect(15 * 16, 0, 2 * 16, 7));
	movablePlatform3 = std::make_unique<MovablePlatform>(&tiletexture, sf::Vector2f(100.0f, 20.0f), sf::Vector2f(1890.0f, 156.0f), sf::Vector2f(2230.0f, -152.0f), 50.0f, sf::IntRect(15 * 16, 0, 2 * 16, 7));
	movablePlatform4 = std::make_unique<MovablePlatform>(&tiletexture, sf::Vector2f(100.0f, 20.0f), sf::Vector2f(2928.0f, 156.0f), sf::Vector2f(2590.0f, -152.0f), 50.0f, sf::IntRect(15 * 16, 0, 2 * 16, 7));

	movablePlatform5 = std::make_unique<MovablePlatform>(&tiletexture, sf::Vector2f(434.0f, 62.0f), sf::Vector2f(2764.0f, 161.0f), sf::Vector2f(2864.0f, 161.0f), 50.0f, sf::IntRect(0, 14 * 16, 14 * 16, 2 * 16));
	//platforms.push_back(Platform(&tiletexture, sf::Vector2f(434.0f, 62.0f), sf::Vector2f(2764.0f, 161.0f), sf::IntRect(0, 14 * 16, 14 * 16, 2 * 16))); //right most movable

	lever1 = std::make_unique<Lever>(&leverTexture, sf::Vector2f(-228.0f, -331.0f));
	lever2 = std::make_unique<Lever>(&leverTexture, sf::Vector2f(2557.0f, 56.0f));
	//lever1 = std::make_unique<Lever>(&leverTexture, sf::Vector2f(233.0f, 100.0f));

	lever2->getBody().setRotation(90.0f);

	door1 = std::make_unique<Door>(&doortexture, sf::Vector2f(100.0f, 150.0f), sf::Vector2f(2405.0f, -248.0f), sf::Vector2u(6, 1), 0.2f);

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
			//printf("%d, %d\n", sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
			if (evnt.mouseButton.button == sf::Mouse::Left) {
				sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

				sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
				printf("%f, %f\n", worldPos.x, worldPos.y);

				if (pauseButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos)))
				{
					GameManager::getInstance().setIsGamePaused(true);
					GameManager::getInstance().playSound("click.wav");
				}

				if (GameManager::getInstance().getIsGameOver()) {
					if (gameOverMenu.getRestartButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos))) {
						printf("Coming");
						Restart();
						GameManager::getInstance().playSound("click.wav");
					}

					if (gameOverMenu.geteExitButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos))) {
						printf("Coming");
						window.close();
					}

					if (gameOverMenu.getOptionButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos))) {
						GameManager::getInstance().setIsLevelCompleted(false);
						std::shared_ptr<Scene> mainMenu = std::make_shared<MainMenu>(window);
						SceneManager::getInstance().ChangeScene(mainMenu);
						GameManager::getInstance().playSound("click.wav");
					}
				}
				if (GameManager::getInstance().getIsGamePaused()) {
					if (pauseMenu.getRestartButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos))) {
						GameManager::getInstance().track1.pause();
						Restart();
						GameManager::getInstance().playSound("click.wav");
					}

					if (pauseMenu.geteExitButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos))) {
						window.close();
						GameManager::getInstance().playSound("click.wav");
					}

					if (pauseMenu.getResumeButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos))) {
						GameManager::getInstance().setIsGamePaused(false);
						GameManager::getInstance().playSound("click.wav");
					}

					if (pauseMenu.getOptionButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos))) {
						GameManager::getInstance().setIsLevelCompleted(false);
						std::shared_ptr<Scene> mainMenu = std::make_shared<MainMenu>(window);
						SceneManager::getInstance().ChangeScene(mainMenu);
						GameManager::getInstance().playSound("click.wav");
					}

				}
				if (GameManager::getInstance().getIsLevelCompleted()) {
					if (completedMenu.getRestartButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos))) {
						GameManager::getInstance().track1.pause();
						Restart();
						GameManager::getInstance().playSound("click.wav");
					}

					if (completedMenu.geteExitButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos))) {
						window.close();
						GameManager::getInstance().playSound("click.wav");
					}

					if (completedMenu.getNextButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos))) {
						GameManager::getInstance().setIsLevelCompleted(false);
						std::shared_ptr<Scene> levelOne = std::make_shared<LevelOne>(window);
						SceneManager::getInstance().ChangeScene(levelOne);
						GameManager::getInstance().playSound("click.wav");
					}

					if (completedMenu.getOptionButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(worldPos))) {
						GameManager::getInstance().setIsLevelCompleted(false);
						std::shared_ptr<Scene> mainMenu = std::make_shared<MainMenu>(window);
						SceneManager::getInstance().ChangeScene(mainMenu);
						GameManager::getInstance().playSound("click.wav");
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

	if (!door1->getIsDoorOpen())
		time += deltaTime;

	timeText.setPosition(view.getCenter() - sf::Vector2f(105, 508));

	std::ostringstream stream;
	stream << std::fixed << std::setprecision(2) << time;

	timeText.setString(stream.str());

	Collider playerCollider = player1->getCollider();
	Collider player2Collider = player2->getCollider();

	player1->Update(deltaTime);
	player2->Update(deltaTime);
	movablePlatform1->Update(lever1->GetIsOn(), deltaTime);
	movablePlatform2->Update(lever1->GetIsOn(), deltaTime);
	movablePlatform3->Update(lever2->GetIsOn(), deltaTime);
	movablePlatform4->Update(lever2->GetIsOn(), deltaTime);
	movablePlatform5->Update(lever2->GetIsOn(), deltaTime);

	pauseButton.setPosition(cameraPos.x - 919.0f, cameraPos.y - 499.0f);

	/*for (Shuriken& shuriken : shurikens) {
		shuriken.Update(deltaTime);*/

		/*if (shuriken.CheckCollision(playerCollider))
			player1->death();
		if (shuriken.CheckCollision(player2Collider))
			player2->death();*/
			//}
	shuriken1->Update(deltaTime);
	shuriken2->Update(deltaTime);
	shuriken3->Update(deltaTime);
	shuriken4->Update(deltaTime);
	shuriken5->Update(deltaTime);
	shuriken6->Update(deltaTime);
	// fanBlade1->Update(deltaTime);
	water1->Update(deltaTime, 1);
	lava1->Update(deltaTime, 0);
	door1->Update(deltaTime);

	sf::Vector2f direction;

	for (int i = 0; i < platforms.size(); i++)
	{
		Platform& platform = platforms[i];

		if (platform.getCollider().CheckCollision(playerCollider, direction, 1.0f))
			player1->OnCollision(direction);

		if (platform.getCollider().CheckCollision(player2Collider, direction, 1.0f))
			player2->OnCollision(direction);
	}

	if (movablePlatform1->getCollider().CheckCollision(player2Collider, direction, 1.0f) || movablePlatform2->getCollider().CheckCollision(player2Collider, direction, 1.0f) || movablePlatform3->getCollider().CheckCollision(player2Collider, direction, 1.0f) || movablePlatform4->getCollider().CheckCollision(player2Collider, direction, 1.0f) || movablePlatform5->getCollider().CheckCollision(player2Collider, direction, 1.0f))
	{
		// printf("Colliding with player");
		player2->OnCollision(direction);
	}
	if (movablePlatform1->getCollider().CheckCollision(playerCollider, direction, 1.0f) || movablePlatform2->getCollider().CheckCollision(playerCollider, direction, 1.0f) || movablePlatform3->getCollider().CheckCollision(playerCollider, direction, 1.0f) || movablePlatform4->getCollider().CheckCollision(playerCollider, direction, 1.0f) || movablePlatform5->getCollider().CheckCollision(playerCollider, direction, 1.0f))
	{
		// printf("Colliding with player");
		player1->OnCollision(direction);
	}

	if (shuriken1->CheckCollision(playerCollider) || shuriken2->CheckCollision(playerCollider) || shuriken3->CheckCollision(playerCollider) || shuriken4->CheckCollision(playerCollider) || shuriken5->CheckCollision(playerCollider) || shuriken6->CheckCollision(playerCollider))
		player1->death();
	if (shuriken1->CheckCollision(player2Collider) || shuriken2->CheckCollision(player2Collider) || shuriken3->CheckCollision(player2Collider) || shuriken4->CheckCollision(player2Collider) || shuriken5->CheckCollision(player2Collider) || shuriken6->CheckCollision(player2Collider))
		player2->death();

	//if (playerCollider.CheckCollision(player2Collider, direction, 0.5f))
	//{
	//	// printf("Colliding with player");
	//	if (player2Collider.CheckCollision(playerCollider, direction, 0.5f))
	//	{
	//		player1->OnCollision(direction);
	//		player2->OnCollision(direction);
	//	}
	//	player1->OnCollision(direction);
	//	player2->OnCollision(direction);
	//}

	if (playerCollider.CheckCollision(player2Collider, direction, 0.5f))
	{
		// printf("Colliding with player");
		if (player2Collider.CheckCollision(playerCollider, direction, 0.5f))
			player1->OnCollision(direction);
		else
			player2->OnCollision(direction);
	}

	if (player1->getPosition().y > 1000 || player2->getPosition().y > 1000)
	{
		GameManager::getInstance().playSound("gameover.wav");
		GameManager::getInstance().setIsGameOver(true);
	}

	// if (lever1->CheckCollision(playerCollider) && GameManager::getInstance().GetKeyPressed(sf::Keyboard::E))
	if ((lever1->CheckCollision(playerCollider) && GameManager::getInstance().GetKeyPressed(sf::Keyboard::S)) || ((lever1->CheckCollision(player2Collider) && GameManager::getInstance().GetKeyPressed(sf::Keyboard::Down))))
	{
		// printf("Touching Player");
		lever1->switchLever();
	}
	if ((lever2->CheckCollision(playerCollider) && GameManager::getInstance().GetKeyPressed(sf::Keyboard::S)) || ((lever2->CheckCollision(player2Collider) && GameManager::getInstance().GetKeyPressed(sf::Keyboard::Down))))
	{
		// printf("Touching Player");
		lever2->switchLever();
	}

	/*if (shuriken1->CheckCollision(playerCollider) || shuriken2->CheckCollision(playerCollider) || shuriken3->CheckCollision(playerCollider))
		player1->death();
	if (shuriken1->CheckCollision(player2Collider) || shuriken2->CheckCollision(player2Collider) || shuriken3->CheckCollision(player2Collider))
		player2->death();*/
		//for (int i = 0; i < shurikens.size(); i++)
		//{
		//	//Shuriken& shuriken = shurikens[i];

		//	if (shuriken.CheckCollision(playerCollider))
		//		player1->death();
		//	if (shuriken.CheckCollision(player2Collider))
		//		player2->death();
		//}
		/*for (Shuriken& shuriken : shurikens) {
			if (shuriken.CheckCollision(playerCollider))
				player1->death();
			if (shuriken.CheckCollision(player2Collider))
				player2->death();
		}*/


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

	if (door1->CheckCollision(playerCollider) && door1->CheckCollision(player2Collider)) {
		door1->setIsDoorOpen(true);
		GameData gamedata;
		GameManager::getInstance().loadData(gamedata);
		if (time < gamedata.bestTimeLv2) {
			//stream << std::fixed << std::setprecision(2) << time;

			gamedata.bestPlayersLv2 = gamedata.player1Name + " and " + gamedata.player2Name + " : " + stream.str();
			gamedata.bestTimeLv2 = time;
			GameManager::getInstance().saveData(gamedata);
		}

	}

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

	movablePlatform1->Draw(window);
	movablePlatform2->Draw(window);
	movablePlatform3->Draw(window);
	movablePlatform4->Draw(window);
	movablePlatform5->Draw(window);

	for (Platform& platform : platforms)
	{
		platform.Draw(window);
	}

	for (Platform& platform : nonCollaidablePlatforms)
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

	shuriken1->Draw(window);
	shuriken2->Draw(window);
	shuriken3->Draw(window);
	shuriken4->Draw(window);
	shuriken5->Draw(window);
	shuriken6->Draw(window);
	// fanBlade1->Draw(window);
	door1->Draw(window);

	lever1->Draw(window);
	lever2->Draw(window);
	player1->Draw(window);
	player2->Draw(window);
	// enemy.Draw(window);

	water1->Draw(window);
	lava1->Draw(window);

	window.draw(timeText);

	window.draw(pauseButton);

	if (GameManager::getInstance().getIsGameOver())
		gameOverMenu.Draw(window, cameraPos);

	if (GameManager::getInstance().getIsGamePaused())
		pauseMenu.Draw(window, cameraPos);

	if (GameManager::getInstance().getIsLevelCompleted())
		completedMenu.Draw(window, cameraPos);

	// view.setCenter(player1->getPosition() - sf::Vector2f(0.0f, 250.0f));
	if (player1->getPosition().x > cameraPos.x + 500)
		cameraPos.x = player1->getPosition().x - 500;
	if (player1->getPosition().x < cameraPos.x - 500 && player1->getPosition().x + 500.0f > 233.0f)
		cameraPos.x = player1->getPosition().x + 500;
	view.setCenter(cameraPos);

	window.setView(view);

	window.display();
}