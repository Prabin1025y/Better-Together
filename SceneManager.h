#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <SFML/Graphics.hpp>
#include "Scene.h"
#include <memory>

class SceneManager
{

private:
    std::shared_ptr<Scene> currentScene;

public:
    void ChangeScene(std::shared_ptr<Scene> newScene);

    void HandleInput(sf::RenderWindow& window);

    void Update(float deltaTime);

    void Render(sf::RenderWindow& window);

    static SceneManager& getInstance();

};

#endif // SCENEMANAGER_H