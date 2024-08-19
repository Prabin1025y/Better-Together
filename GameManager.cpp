#include "GameManager.h"

GameManager& GameManager::getInstance()
{
	static GameManager instance;
	return instance;
}

GameManager::GameManager() : isGameOver(false), pressedKey(sf::Keyboard::End), isGamePaused(false), isLevelCompleted(false) {
	track1.setVolume(50);
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

void GameManager::loadData(GameData& gamedata)
{
	inF.open("playerData.dat");
	if (inF.is_open()) {
		std::getline(inF, gamedata.player1Name);
		std::getline(inF, gamedata.player2Name);
		/*std::getline(inF, gamedata.bestTimeLv1);
		std::getline(inF, gamedata.bestTimeLv2);*/
		inF >> gamedata.bestTimeLv1;
		inF.ignore();
		inF >> gamedata.bestTimeLv2;
		inF.ignore();
		std::getline(inF, gamedata.bestPlayersLv1);
		std::getline(inF, gamedata.bestPlayersLv2);
		inF.close();
	}
	else {
		std::cerr << "Error opening file for reading" << std::endl;
	}

	//inF.open("playerData.dat", std::ios::binary);
	//if (inF.is_open()) {
	//	inF.read(reinterpret_cast<char*>(&gamedata), sizeof(gamedata));
	//	//gameData = this->gameData;
	//	inF.close();
	//}
	//else {
	//	printf("Error opening file for reading:");
	//}

}

void GameManager::saveData(GameData& gamedata)
{
	outF.open("playerData.dat", std::ios::trunc);
	if (outF.is_open()) {
		outF << gamedata.player1Name << std::endl;
		outF << gamedata.player2Name << std::endl;
		outF << gamedata.bestTimeLv1 << std::endl;
		outF << gamedata.bestTimeLv2 << std::endl;
		outF << gamedata.bestPlayersLv1 << std::endl;
		outF << gamedata.bestPlayersLv2 << std::endl;
		outF.close();
	}
	else {
		std::cerr << "Error opening file for writing" << std::endl;
	}

	// outF.open("playerData.dat", std::ios::binary | std::ios::trunc | std::ios::out);
	//if (outF.is_open()) {
	//	outF.write(reinterpret_cast<char*>(&gamedata), sizeof(gamedata));
	//	//this->gameData = gameData;
	//	outF.close();
	//}
	//else {
	//	printf("Error opening file for writing");
	//}
}

void GameManager::changeSong(std::string songName, bool loop)
{
	track1.stop();
	track1.openFromFile(songName);
	track1.play();
	track1.setLoop(loop);
}

void GameManager::playSound(std::string songName)
{
	sound.stop();
	soundBuffer.loadFromFile(songName);
	sound.setBuffer(soundBuffer);
	sound.play();
}

GameManager::~GameManager() {
	track1.stop();
	sound.resetBuffer();
	sound.stop();
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
