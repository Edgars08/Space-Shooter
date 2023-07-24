#include "Space.h"
#include "Definations.h"

namespace Edgars
{
    Space::Space(GameDataRef data) : _data(data)
    {
    }

    void Space::InitSpace()
    {
        _data->assets.LoadTexture("gamestateBackground", GAME_STATE_BACKGROUND_FILEPATH);

        this->_background.setTexture(_data->assets.GetTexture("gamestateBackground"));
        this->_background_1.setTexture(_data->assets.GetTexture("gamestateBackground"));

        _background.setScale(1.33333333f, 1.55210643f);
        _background_1.setScale(1.33333333f, 1.55210643f);

        _background.setPosition(sf::Vector2f(0.0, 0.0));
        _background_1.setPosition(sf::Vector2f(0.0, 0 - _background_1.getGlobalBounds().height));

        _spaceSprites.push_back(_background);
        _spaceSprites.push_back(_background_1);
    }
    void Space::MoveSpace(float dt)
    {
        float movement = SPACE_SPEED * dt;

        for (unsigned int i = 0; i < _spaceSprites.size(); i++)
        {
            _spaceSprites[i].move(0.0f, movement);
            if (_spaceSprites[i].getGlobalBounds().top > _data->window.getSize().y)
            {
                _spaceSprites[i].setPosition(sf::Vector2f(0.0f, 0.0f - _spaceSprites[i].getGlobalBounds().height));
            }
        }
      
    }
    void Space::DrawSpace()
    {
        for (unsigned int i = 0; i < _spaceSprites.size(); i++)
        {
            _data->window.draw(_spaceSprites[i]);
        }
    }
    sf::FloatRect Space::getBoundSpace() const
    {
        return sf::FloatRect();
    }
}