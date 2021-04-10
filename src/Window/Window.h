/**
 * Window Implementation SFML
 * 
 * 09/04/21 Here we use SFML RenderWindow directly throught inheritance
 */

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "IWindow.h"
#include <SFML/Graphics/RenderWindow.hpp>

class Window: /* public IWindow, */ public sf::RenderWindow {
    public:
        /*Window(unsigned int width, 
            unsigned int height, 
            unsigned int bitsPerPixel, // default 32 
            std::string title) {}*/;
        ~Window() {};

        /* virtual void create(unsigned int width, 
                            unsigned int height, 
                            unsigned int bitsPerPixel, //(default 32) 
                            std::string title) {};
        virtual void open() {};
        virtual void close() {}; */
    protected:

    private:
};

#endif