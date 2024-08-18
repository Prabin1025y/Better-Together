#pragma once

#include <string>

class FileData
{
private:
	std::string currentPlayer1, currentPlayer2, bestPlayer1Lv1, bestPlayer2Lv1, bestPlayer1Lv2, bestPlayer2Lv2;
	float bestTimeLv1, bestTimeLv2;

public:
	FileData();


	std::string getPlayer1();

	std::string getPlayer2();

	void setPlayer1(std::string player1Name);

	void setPlayer2(std::string player2Name);

	void Level1Best();

	void Level2Best();

};

