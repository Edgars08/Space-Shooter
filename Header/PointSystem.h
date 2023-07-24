#ifndef POINTSYSTEM_H
#define POINTSYSTEM_H

#include "StateMachine.h"
#include "InputManager.h"
#include "Game.h"
#include "Definations.h"
#include <SFML/Graphics.hpp>

namespace Edgars
{
    class PointSystem
    {
    public:
        PointSystem(GameDataRef data);
        ~PointSystem(){};
        void InitVariables();
        void LoseLife(int _point);
        void setLife(int _point);
        int getPoints() const;
        int getLife() const;
        int getLifeMax() const;

    private:
        GameDataRef _data;
        int points;
        int LifeMax;
        int Life;
    };
}
#endif