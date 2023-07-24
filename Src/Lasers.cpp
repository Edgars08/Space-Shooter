#include "Lasers.h"

namespace Edgars
{
    Lasers::Lasers(GameDataRef data, sf::Vector2f pos) : _data(data)
    {
        this->SpawnLasers(pos);
    }
    void Lasers::SpawnLasers(sf::Vector2f pos)
    {
        _data->assets.LoadTexture("lasers", LASER_FILEPATH);
        _laser.setTexture(_data->assets.GetTexture("lasers"));
        _laser.setPosition(pos);
        direction = sf::Vector2f(0.0f, -1.0f);
    }
    void Lasers::UpdateLasers(float dt)
    {
        _laser.move(dt * LASER_SPEED * direction);
    }
    void Lasers::DrawLasers()
    {
        _data->window.draw(_laser);
    }
    sf::FloatRect Lasers::getBound() const
    {
        return _laser.getGlobalBounds();
    }
}