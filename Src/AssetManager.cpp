#include "AssetManager.h"

namespace Edgars
{
    void AssetManager::LoadTexture(std::string name, std::string fileName)
    {
        sf::Texture tex;
        if (tex.loadFromFile(fileName))
        {
            // use the key to access the value.
            this->_textures[name] = tex; // here we assigning the key(name) its value(path)
        }
    }
    sf::Texture &AssetManager::GetTexture(std::string name)
    {
        return this->_textures.at(name);
    }
    void AssetManager::LoadFont(std::string name, std::string fileName)
    {
        sf::Font font;
        if (font.loadFromFile(fileName))
        {
            this->_fonts[name] = font; // here we assigning the key its value
        }
    }
    sf::Font &AssetManager::GetFont(std::string name)
    {
        return this->_fonts.at(name);
    }
}