#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP

#include "IScene.h"
#include "Pacman.h"
#include "ErrorNone.h"

class GameScene: public IScene {
    public:
        GameScene(sf::Texture &);
        
        Error load(sf::Texture &);
        void update(sf::Event &e, sf::RenderWindow &);
        void draw(sf::RenderWindow &);

    protected:

    private:
        Pacman pacman;
};

#endif