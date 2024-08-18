#include "FileData.h"


FileData::FileData() :bestTimeLv1(0.0f), bestTimeLv2(0.0f) {
	currentPlayer1 = "Player 1";
	currentPlayer2 = "Player 2";
}


std::string FileData::getPlayer1() {
	return currentPlayer1;
}

std::string FileData::getPlayer2() {
	return currentPlayer2;
}

void FileData::setPlayer1(std::string player1Name) {
	currentPlayer1 = player1Name;
}

void FileData::setPlayer2(std::string player2Name) {
	currentPlayer2 = player2Name;
}

void FileData::Level1Best() {
	bestPlayer1Lv1 = currentPlayer1;
	bestPlayer2Lv1 = currentPlayer2;
}

void FileData::Level2Best() {
	bestPlayer1Lv2 = currentPlayer1;
	bestPlayer2Lv2 = currentPlayer2;
}


