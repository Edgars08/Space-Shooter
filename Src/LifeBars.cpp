#include "LifeBars.h"

namespace Edgars
{
    LifeBars ::LifeBars(GameDataRef data) : _data(data)
    {
        this->InitLifeBar(1.0f);
        this->InitLifeBarBack();
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
        // this->LifeBar.setSize(sf::Vector2f(percent * 200.0f, LifeBar.getSize().y));
        this->InitLifeBar(percent);
    }
    void LifeBars::DrawLifeBar()
    {
        _data->window.draw(LifeBar);
        _data->window.draw(LifeBarBack);
    }
}