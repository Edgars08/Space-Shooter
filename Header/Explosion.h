#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "StateMachine.h"
#include "InputManager.h"
#include "Game.h"
#include "Definations.h"
#include <SFML/Graphics.hpp>

namespace Edgars
{

    class Explosion
    {
    public:
        Explosion(GameDataRef data, sf::Vector2f pos, std::string filepath);
        ~Explosion(){};
        void SpawnExplosion(sf::Vector2f pos, std::string filepath);
        void UpdateExplosion(float dt);
        sf::Vector2f getExplosionPosition() const;
        sf::FloatRect getBound() const;
        void DrawExplosion();

    private:
        GameDataRef _data;
        sf::Sprite _explosion;
  
    };
}
#endif