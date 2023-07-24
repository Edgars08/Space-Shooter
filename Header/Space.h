#ifndef SPACE_H
#define SPACE_H


#include "Game.h"
#include <vector>

namespace Edgars
{
    class Space
    {
    public:
        Space(GameDataRef data);
        ~Space(){};
        void InitSpace();
        void MoveSpace(float dt);
        void DrawSpace();

        sf::FloatRect getBoundSpace() const;

    private:
        GameDataRef _data;
        std::vector<sf::Sprite> _spaceSprites;
        sf::Sprite _background_1;
        sf::Sprite _background;
    };
}
#endif