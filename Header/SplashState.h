#ifndef SPLASHSTATE_H
#define SPLASHSTATE_H

#pragma once

#include "State.h"
#include "Game.h"
#include<SFML/Graphics.hpp>

namespace Edgars
{
    class SplashState :public State
    {
    public:
        SplashState(GameDataRef data);
        ~SplashState(){};
        void InitState();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;
        sf::Clock _clock;
        sf::Sprite _background;
    };
}
#endif