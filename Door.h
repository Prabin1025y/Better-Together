#ifndef DOOR_H
#define DOOR_H

#include <SFML/Graphics.hpp>
#include "Collidable.h"
#include "AnimationAll.h"

class Door : public Collidable
{
private:
	sf::RectangleShape body;
	bool isDoorOpen;
	AnimationAll animation;

	float totalTime = 0.0f;

public:
	Door(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, sf::Vector2u imageCount, float switchTime);
	~Door();

	void Update(float deltaTime);


	void setIsDoorOpen(bool value);

	bool getIsDoorOpen() { return isDoorOpen; }

	void Draw(sf::RenderWindow& window);
};

#endif // DOOR_H