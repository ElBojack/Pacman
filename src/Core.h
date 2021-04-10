/**
 * 
 * 
 */

#ifndef CORE_HPP
#define CORE_HPP

//#include "Window.h"
#include "ErrorHandler.h"
#include "IScene.h"

// INCLUDE SPECIFIC SCENE
#include "GameScene.h"

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

class Core {
    public:
        Core();
        ~Core() {};
        // Must pass the return type as Exit code (e.g: 84)
        void load();
        void loop();
    protected:

    private:
        sf::RenderWindow window;
        ErrorHandler errHandler;
        std::vector<sf::Texture> textures;
        std::unique_ptr<IScene> currentScene;
};

#endif