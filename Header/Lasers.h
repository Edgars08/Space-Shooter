#ifndef LASERS_H
#define LASERS_H

#pragma once

#include "StateMachine.h"
#include "InputManager.h"
#include "Game.h"
#include "Definations.h"
#include <SFML/Graphics.hpp>

namespace Edgars
{

    class Lasers
    {
    public:
        Lasers(GameDataRef data, sf::Vector2f pos);
        ~Lasers(){};
        void SpawnLasers(sf::Vector2f pos);
        void UpdateLasers(float dt);
        sf::FloatRect getBound() const;
        void DrawLasers();

    private:
        GameDataRef _data;
        sf::Sprite _laser;
        sf::Vector2f direction;
        std::vector<sf::Sprite>
            _laserSprites;
    };
}
#endif