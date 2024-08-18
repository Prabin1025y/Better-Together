#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<string>
#include <iostream>
#include "GameData.h"
#include "fstream"

class GameManager
{
public:
	static GameManager& getInstance(); // Singleton instance
	bool getIsGameOver() const { return isGameOver; }
	void setIsGameOver(bool value);

	bool getIsGamePaused() const { return isGamePaused; }
	void setIsGamePaused(bool value);

	bool getIsLevelCompleted() const { return isLevelCompleted; }
	void setIsLevelCompleted(bool value);

	void SetKeyPressed(sf::Keyboard::Key key);
	bool GetKeyPressed(sf::Keyboard::Key key);

	void loadData(GameData& gamedata);
	void saveData(GameData& gamedata);

	void changeSong(std::string songName, bool loop);




	sf::Music track1;

	//FileData getFile() {
	//	return file;
	//}


	//void keyReleased(sf::Keyboard::Key key);

public:
	sf::Vector2f vectorZero = sf::Vector2f(0.0f, 0.0f);

private:
	GameManager();
	bool isGameOver;
	bool isGamePaused;
	bool isLevelCompleted;
	sf::Keyboard::Key pressedKey;
	std::ofstream outF;
	std::ifstream inF;
	~GameManager();
};

#endif // GAMEMANAGER_H