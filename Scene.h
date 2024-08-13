#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>

class Scene
{
protected:
    const float VIEW_HEIGHT = 1080.0f;
    const float VIEW_WIDTH = 1920.0f;
public:
    void ResizeWindow(const sf::RenderWindow& window, sf::View& view);
    virtual ~Scene() = default;
    virtual void HandleInput(sf::RenderWindow& window) = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Render(sf::RenderWindow& window) = 0;
};

#endif // SCENE_H