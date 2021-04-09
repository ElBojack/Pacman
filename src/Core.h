/**
 * 
 * 
 */

//#include "Window.h"
#include "ErrorHandler.h"

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
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
};