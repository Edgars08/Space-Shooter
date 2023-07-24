#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#pragma once
#include <SFML/Graphics.hpp>
#include "Definations.h"

namespace Edgars
{

    class InputManager
    {
    public:
        InputManager();
        ~InputManager(){};
        bool IsDirectionClicked(sf::Keyboard::Key button);
        bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
        sf::Vector2i GetMousePosition(sf::RenderWindow &window);

    private:
       
    };
}
#endif