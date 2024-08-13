#include "Animation.h"
#include "GameManager.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / (float)imageCount.x;
	uvRect.height = texture->getSize().y / (float)imageCount.y;

	// printf("%d, %d\n", uvRect.width, uvRect.height);
}

void Animation::setCurrentImageX(int currentImageX) { currentImage.x = currentImageX; }

void Animation::Update(int row, float deltaTime, int maxCol, bool facingRight, Player* currentPlayer)
{
	// printf("%d, %d\n", imageCount.x, imageCount.y);
	// GameManager& gameManager = GameManager::getInstance();

	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;

		// if (maxCol > 1)
		// {
		currentImage.x++;
		// }

		if (currentImage.x >= maxCol)
		{
			// if (gameManager.getCanPerformActionByPlayer1() || gameManager.getCanPerformActionByPlayer2())
			if (currentImage.y == 6) {
				currentImage.x = maxCol - 1;
				GameManager::getInstance().setIsGameOver(true);
			}
			else if (currentPlayer->getCanPerformAction())
				currentImage.x = 0;
			else
			{
				currentImage.x = 0;
				currentImage.y = 0;
				currentPlayer->setCanPerformAction(true);
				// gameManager.setCanPerformActionByPlayer2(true);
			}
		}
	}

	uvRect.top = currentImage.y * uvRect.height;

	if (facingRight)
	{
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}

	// printf("%d, %d, %d, %d\n", uvRect.left, uvRect.top, uvRect.width, uvRect.height);
}

Animation::~Animation()
{
}
