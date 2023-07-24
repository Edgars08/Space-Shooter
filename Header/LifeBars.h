#ifndef LIFEBARS_H
#define LIFEBARS_H

#include "StateMachine.h"
#include "InputManager.h"
#include "Game.h"
#include "Definations.h"
#include <SFML/Graphics.hpp>

namespace Edgars
{

    class LifeBars
    {
    public:
        LifeBars(GameDataRef data);
        ~LifeBars(){};
        void InitLifeBar(float percent);
        void InitLifeBarBack();
        void UpdateLifeBar(float percent);
        void DrawLifeBar();

    private:
        GameDataRef _data;
        sf::RectangleShape LifeBar;
        sf::RectangleShape LifeBarBack;
    };
}
#endif