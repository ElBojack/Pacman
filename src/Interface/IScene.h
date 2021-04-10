/**
 * 
 **/


#ifndef ISCENE_HPP
#define ISCENE_HPP

#include "Error.h"

#include <SFML/Graphics/RenderWindow.hpp>

enum SceneState: sf::Uint32 {
        Off = 0,
        On = 1
};

class IScene {
    public:
        virtual ~IScene() {};

        virtual Error load(sf::Texture &) = 0;
        virtual void update(sf::Event &e, sf::RenderWindow &) = 0;
        virtual void draw(sf::RenderWindow &) = 0;
};

#endif