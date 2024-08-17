#ifndef ANIMATIONALL_H
#define ANIMATIONALL_H

#include <SFML/Graphics.hpp>
 #include "GameManager.h"
// #include "Player.h"

class AnimationAll
{

private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;
    bool infinite;

public:
    sf::IntRect uvRect;

public:
    AnimationAll() {}
    AnimationAll(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, bool infinite);
    ~AnimationAll();
    void Update(int row, float deltaTime, int maxCol);
    // void setCurrentImageX(int currentImageX);
};

#endif // ANIMATIONALL_H