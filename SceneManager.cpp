#include "SceneManager.h"

void SceneManager::ChangeScene(std::shared_ptr<Scene> newScene)
{
	currentScene = std::move(newScene);
}

void SceneManager::HandleInput(sf::RenderWindow& window)
{
	if (currentScene)
		currentScene->HandleInput(window);
}

void SceneManager::Update(float deltaTime)
{
	if (currentScene)
		currentScene->Update(deltaTime);
}

void SceneManager::Render(sf::RenderWindow& window)
{
	if (currentScene)
		currentScene->Render(window);
}

SceneManager& SceneManager::getInstance()
{
	static SceneManager instance;
	return instance;
}