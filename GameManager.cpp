#include "GameManager.h"

GameManager& GameManager::getInstance()
{
	static GameManager instance;
	return instance;
}

GameManager::GameManager() : isGameOver(false), pressedKey(sf::Keyboard::End), isGamePaused(false) {}

void GameManager::setIsGameOver(bool value)
{
	isGameOver = value;
}

void GameManager::setIsGamePaused(bool value)
{
	isGamePaused = value;
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
