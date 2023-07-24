#include "PointSystem.h"
#include "Definations.h"

namespace Edgars
{
    PointSystem::PointSystem(GameDataRef data) : _data(data)
    {
        this->InitVariables();
    }
    void PointSystem::InitVariables()
    {
        this->points = 5;
        this->LifeMax = LIFE_MAX;
        this->Life = this->LifeMax;
    }
    void PointSystem::LoseLife(int _point)
    {
        if (this->Life < 0)
        {
            this->Life = 0;
        }
        else
        {
            this->Life -= _point;
        }
    }
    void PointSystem::setLife(int _point)
    {
        this->Life = _point;
    }
    int PointSystem::getPoints() const
    {
        return points;
    }
    int PointSystem::getLife() const
    {
        return Life;
    }
    int PointSystem::getLifeMax() const
    {
        return LifeMax;
    }
}