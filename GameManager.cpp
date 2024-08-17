#include "GameManager.h"

GameManager& GameManager::getInstance()
{
	static GameManager instance;
	return instance;
}

GameManager::GameManager() : isGameOver(false), pressedKey(sf::Keyboard::End), isGamePaused(false), isLevelCompleted(false) {
	track1.openFromFile("track1.wav");
	track1.play();
	track1.setLoop(true);
}

void GameManager::setIsGameOver(bool value)
{
	isGameOver = value;
}

void GameManager::setIsGamePaused(bool value)
{
	isGamePaused = value;
}

void GameManager::setIsLevelCompleted(bool value)
{
	isLevelCompleted = value;
}

void GameManager::SetKeyPressed(sf::Keyboard::Key key)
{
	pressedKey = key;
}

bool GameManager::GetKeyPressed(sf::Keyboard::Key key)
{
	if (key == pressedKey)
	{
		pressedKey = sf::Keyboard::End;
		return true;
	}
	else
		return false;
}

// void GameManager::keyReleased(sf::Keyboard::Key key){
//     switch (key)
//     {
//     case sf::Keyboard::E:
//             // canPerformAction = true;
//             // printf("E");
//         break;

//     default:
//         break;
//     }
// }
