#ifndef SPACESHIP_H
#define SPACESHIP_H

#pragma once
#include "StateMachine.h"
#include "InputManager.h"
#include "Game.h"
#include "Definations.h"
#include <SFML/Graphics.hpp>

namespace Edgars
{
class SpaceShip
{
public:
    SpaceShip(GameDataRef data);
    ~SpaceShip(){};
    void InitSpaceShip();
    void MoveSpaceShip(float dt);
    void CheckWindowCollision();
    sf::Vector2f getPosition()const;
    sf::FloatRect getBound() const;
    void DrawSpaceShip();

private:
    GameDataRef _data;
    sf::Sprite _player;
    int _mDirection;
};
}
#endif