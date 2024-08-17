#include "AnimationAll.h"
// #include "GameManager.h"

AnimationAll::AnimationAll(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, bool infinite)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;
	this->infinite = infinite;

	uvRect.width = texture->getSize().x / (float)imageCount.x;
	uvRect.height = texture->getSize().y / (float)imageCount.y;

	// printf("%d, %d\n", texture->getSize().x, texture->getSize().y);
}

// void AnimationAll::setCurrentImageX(int currentImageX){currentImage.x = currentImageX;}

void AnimationAll::Update(int row, float deltaTime, int maxCol)
{

	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;

		currentImage.x++;

		if (currentImage.x >= maxCol)
		{
			if (infinite)
				currentImage.x = 0;
			else {
				currentImage.x = maxCol - 1;
			}
		}
	}
	uvRect.left = currentImage.x * uvRect.width;

	uvRect.top = currentImage.y * uvRect.height;
}

AnimationAll::~AnimationAll()
{
}
