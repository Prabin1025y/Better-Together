#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SFML/Graphics.hpp>

class GameManager
{
public:
    static GameManager& getInstance(); // Singleton instance
    bool getIsGameOver() const { return isGameOver; }
    void setIsGameOver(bool value);
    
    bool getIsGamePaused() const { return isGamePaused; }
    void setIsGamePaused(bool value);

    void SetKeyPressed(sf::Keyboard::Key key);
    bool GetKeyPressed(sf::Keyboard::Key key);


    //void keyReleased(sf::Keyboard::Key key);

public:
    sf::Vector2f vectorZero = sf::Vector2f(0.0f, 0.0f);

private:
    GameManager();
    bool isGameOver;
    bool isGamePaused;
    sf::Keyboard::Key pressedKey;
};

#endif // GAMEMANAGER_H