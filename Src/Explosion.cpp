#include "Explosion.h"
#include "Definations.h"

 namespace Edgars{
     Explosion::Explosion(GameDataRef data,sf::Vector2f pos, std::string filepath)
     {
        this->SpawnExplosion(pos,filepath);
     }
     void Explosion::SpawnExplosion(sf::Vector2f pos, std::string filepath)
     {
        _data->assets.LoadTexture("explosion",filepath);
        _explosion.setTexture(_data->assets.GetTexture("explosion"));
        _explosion.setPosition(pos);
     }
     void Explosion::UpdateExplosion(float dt)
     {
     }
     sf::Vector2f Explosion::getExplosionPosition() const
     {
         return _explosion.getPosition();
     }
     sf::FloatRect Explosion::getBound() const
     {
         return _explosion.getGlobalBounds();
     }
     void Explosion::DrawExplosion()
     {
        _data->window.draw(_explosion);
     }
 }