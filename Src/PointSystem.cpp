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
        }
    int PointSystem::getPoints() const
    {
        return points;
    }
}