#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Edgars
{
    class AssetManager
    {
    public:
        AssetManager(){};
        ~AssetManager(){};
        // name is the key - filename is value
        void LoadTexture(std::string name, std::string fileName);
        sf::Texture &GetTexture(std::string name);
        void LoadFont(std::string name, std::string fileName);
        sf::Font &GetFont(std::string name);

    private:
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Font> _fonts;
    };
}
#endif