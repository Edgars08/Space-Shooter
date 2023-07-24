#ifndef METEORS_H
#define METEORS_H

#include "StateMachine.h"
#include "InputManager.h"
#include "Game.h"
#include "Definations.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace Edgars
{

    class Meteors
    {
    public:
        Meteors(GameDataRef data, std::string filename, std::string filepath);
        ~Meteors(){};
        void SpawnMeteor(std::string filename, std::string filepath);
        void UpdateMeteor(float dt);
        sf::Vector2f getMeteorsPosition() const;
        sf::FloatRect getBound() const;
        void DrawMeteors();

    private:
        GameDataRef _data;
        sf::Sprite _meteor;
        sf::Vector2f direction;
    };
}
#endif