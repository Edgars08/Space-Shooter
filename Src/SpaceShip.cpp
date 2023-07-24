#include "SpaceShip.h"

namespace Edgars
{
    SpaceShip::SpaceShip(GameDataRef data) : _data(data)
    {
    }
    void SpaceShip::InitSpaceShip()
    {
        _data->assets.LoadTexture("spaceship", SPACE_SHIP_PLAYER_FILEPATH);
        _player.setTexture(_data->assets.GetTexture("spaceship"));

        _player.setPosition(sf::Vector2f(_data->window.getSize().x / 2, _data->window.getSize().y - _player.getGlobalBounds().height * 1.2));

        _mDirection = DIRECTION::mStill;
    }
    void SpaceShip::MoveSpaceShip(float dt)
    {
        int direction;
        if (_data->input.IsDirectionClicked(sf::Keyboard::Right))
        {
            float movement = SPACE_SHIP_SPEED * dt;
            _player.move(sf::Vector2f(movement, 0));
            _mDirection = DIRECTION::mRight;
        }
        else if (_data->input.IsDirectionClicked(sf::Keyboard::Left))
        {
            float movement = SPACE_SHIP_SPEED * dt;
            _player.move(sf::Vector2f(-movement, 0));
            _mDirection = DIRECTION::mLeft;
        }
        else
        {
            _mDirection = DIRECTION::mStill;
        }
    }
    void SpaceShip::CheckWindowCollision()
    {
        if (_player.getGlobalBounds().left < 0) // LEFT
        {
            _player.setPosition(sf::Vector2f(0.0f, _player.getGlobalBounds().top));
        }
        if (_player.getGlobalBounds().left + _player.getGlobalBounds().width > _data->window.getSize().x) // RIGHT
        {
            _player.setPosition(sf::Vector2f(_data->window.getSize().x - _player.getGlobalBounds().width, _player.getGlobalBounds().top));
        }
    }
    sf::Vector2f SpaceShip::getPosition() const
    {
        return _player.getPosition();
    }
    sf::FloatRect SpaceShip::getBound() const
    {
        return _player.getGlobalBounds();
    }
    void SpaceShip::DrawSpaceShip()
    {
        _data->window.draw(_player);
    }
}