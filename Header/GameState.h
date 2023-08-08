#ifndef GAMESTATE_H
#define GAMESTATE_H

#pragma once

#include "StateMachine.h"
#include "InputManager.h"
#include "Game.h"
#include "SpaceShip.h"
#include "Space.h"
#include "Lasers.h"
#include "Meteors.h"
#include "PointSystem.h"
#include "LifeBars.h"

namespace Edgars
{
    class GameState : public State
    {
    public:
        GameState(GameDataRef data);
        ~GameState();
        void InitState();
        void HandleInput();
        void ShootLasers();
        void InitMeteors();
        void InitScore();
        void UpdateScore();
        void CheckMeteorLaserCollisionBig();
        void CheckMeteorLaserCollisionSmall();
        void CheckMeteorPlayerCollision();
        void UpdateLaser(float dt);
        void UpdateMeteors(float dt);
        void Update(float dt);
        void DrawScore();
        void Draw(float dt);

    private:
        GameDataRef _data;
        sf::Sprite _background;
        sf::Clock clock_1;
        sf::Clock clock_2;
        int _score;
        sf::Text pointtext;
        sf::Font fontText;

        // Objects
        SpaceShip *spaceship;
        Space *space;
        PointSystem *pointsystem;
        LifeBars *lifebar;
        std::vector<Lasers *> lasers;
        std::vector<Meteors *> meteorsBig;
        std::vector<Meteors *> meteorsSmall;
    };
}
#endif