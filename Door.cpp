#include "Door.h"

Door::Door(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, sf::Vector2u imageCount, float switchTime) : Collidable(body), animation(texture, imageCount, switchTime, false)
{
	body.setPosition(position);
	body.setTexture(texture);
	body.setSize(size);
	body.setOrigin(body.getSize() / 2.0f);
	isDoorOpen = false;

}

void Door::setIsDoorOpen(bool value)
{
	isDoorOpen = value;
}

void Door::Update(float deltaTime)
{




	if (isDoorOpen) {
		animation.Update(0, deltaTime, 6);
		totalTime += deltaTime;

		if (totalTime > 2)
			GameManager::getInstance().setIsLevelCompleted(true);
	}

	if (animation.uvRect.left > 0 && animation.uvRect.left < 200)
		GameManager::getInstance().playSound("levelCompleted.wav");

	body.setTextureRect(animation.uvRect);



}

void Door::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

Door::~Door() {}