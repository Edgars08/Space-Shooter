#include "LifeBars.h"

namespace Edgars
{
    LifeBars ::LifeBars(GameDataRef data) : _data(data)
    {
        this->LifeMax = 100;
        this->Life = this->LifeMax;
    }
    void LifeBars::InitLifeBar(float percent)
    {
        this->LifeBar.setPosition(sf::Vector2f(100.0f, 20.0f));
        this->LifeBar.setSize(sf::Vector2f(percent * 200.0f, 20.0f));
        this->LifeBar.setFillColor(sf::Color::Green);
    }
    void LifeBars::InitLifeBarBack()
    {
        LifeBarBack.setPosition(sf::Vector2f(100.0f, 20.0f));
        this->LifeBarBack.setSize(sf::Vector2f(200.0f, 20.0f));
        this->LifeBarBack.setFillColor(sf::Color(30, 30, 30, 200));
    }
    void LifeBars::UpdateLifeBar(float percent)
    {
        this->InitLifeBar(percent);
    }

    void LifeBars::LoseLife()
    {
        if (this->Life < 0)
        {
            this->Life = 0;
        }
        else
        {
            this->Life -= LOSE_POINTS;
        }
    }
    void LifeBars::setLife(int _point)
    {
        this->Life = _point;
    }
    int LifeBars::getLife() const
    {
        return Life;
    }
    int LifeBars::getLifeMax() const
    {
        return LifeMax;
    }
    void LifeBars::DrawLifeBar()
    {
        _data->window.draw(LifeBar);
        _data->window.draw(LifeBarBack);
    }
}