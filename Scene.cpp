#include "Scene.h"
#include <math.h>

void Scene::ResizeWindow(const sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = static_cast<float>(window.getSize().x) / static_cast<float>(window.getSize().y);
    // sf::Vector2u windowSize(abs(window.getSize().x * aspectRatio), (unsigned int)window.getSize().y);

    // window.setSize(sf::Vector2u((unsigned int)window.getSize().x * aspectRatio, (unsigned int)window.getSize().y));
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}