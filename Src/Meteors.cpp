#include "Meteors.h"
#include "Definations.h"
#include <string>

namespace Edgars
{
    Meteors::Meteors(GameDataRef data, std::string filename, std::string filepath) : _data(data)
    {
        this->SpawnMeteor(filename, filepath);
    }
    void Meteors::SpawnMeteor(std::string filename, std::string filepath)
    {
        _data->assets.LoadTexture(filename, filepath);
        _meteor.setTexture(_data->assets.GetTexture(filename));
        int temp = static_cast<int>(_data->window.getSize().x - _meteor.getGlobalBounds().width);
        _meteor.setPosition(sf::Vector2f(static_cast<float>(rand() % temp), 0.0f - static_cast<float>(rand() % 50) - INITIAL_METEOR_HEIGHT));
        _meteor.setScale(2.0f, 2.0f);
        direction = sf::Vector2f(0.0f, 1.0f);
    }
    void Meteors::UpdateMeteor(float dt)
    {
        _meteor.move(dt * METEOR_SPEED * direction);
    }
    sf::Vector2f Meteors::getMeteorsPosition() const
    {
        return _meteor.getPosition();
    }
    void Meteors::DrawMeteors()
    {
        _data->window.draw(_meteor);
    }
    sf::FloatRect Meteors::getBound() const
    {
        return _meteor.getGlobalBounds();
    }
}
