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
        void LoseLife();
        void setLife(int _point);
        int getLife() const;
        int getLifeMax() const;
        void DrawLifeBar();

    private:
        GameDataRef _data;
        int LifeMax;
        int Life;
        sf::RectangleShape LifeBar;
        sf::RectangleShape LifeBarBack;
    };
}
#endif