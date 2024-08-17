#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <sstream>

class Textbox {

private:
	sf::RectangleShape bg;
	sf::Text textbox;
	std::ostringstream text;
	bool isSelected = false;
	bool hasLimit = false;
	int limit = 0;

	const int DELETE_KEY = 8;
	const int ENTER_KEY = 13;
	const int ESCAPE_KEY = 27;

	void inputLogic(int charTyped);

	void deleteLastChar();
public:
	Textbox(int size, sf::Color color, bool sel);

	void setFont(sf::Font& fonts);

	void setPosition(sf::Vector2f point);

	void setLimit(bool ToF);

	void setLimit(bool ToF, int lim);

	void setSelected(bool sel);

	std::string getText();

	sf::RectangleShape getTextBoxBg() { return bg; }

	void Draw(sf::RenderWindow& window);

	void typedOn(sf::Event input);

};
