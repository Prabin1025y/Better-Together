#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "Player.h"

class Animation
{

private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;

public:
    sf::IntRect uvRect;

public:
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    ~Animation();
    // void Update(int row, float deltaTime, int maxCol, bool facingRight, GameManager& gameManager);
    void Update(int row, float deltaTime, int maxCol, bool facingRight, Player* currentPlayer);
    void setCurrentImageX(int currentImageX);
};

#endif // ANIMATION_H