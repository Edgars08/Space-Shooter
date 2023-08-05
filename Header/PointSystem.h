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
        int getPoints() const;
       

    private:
        GameDataRef _data;
        int points;
    };
}
#endif