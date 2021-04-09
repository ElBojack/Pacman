/**
 * 
 * 
 */

#include "Core.h"

// Temp include sf::Event
#include <SFML/Window/Event.hpp>

Core::Core(): window(), errHandler() {

}

void Core::load() {
    /** Load configuration **/

    /** Load element according to the configuration **/
    window.create(sf::VideoMode(720, 480), "Menu");
    window.setFramerateLimit(60);
}
#include "Button.h"
void Core::loop() {
    sf::Font f;
    f.loadFromFile("ressources/arial.ttf");
    Button b(std::string("Boutton"), f, sf::Vector2f(130,130));

    while (window.isOpen()) {
        // Event processing
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Request for closing the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update entities
        b.update(event, window);

        // Clear the whole window before rendering a new frame
        window.clear();

        // Draw entities
        window.draw(b);
        // End the current frame and display its contents on screen
        window.display();
    }
}