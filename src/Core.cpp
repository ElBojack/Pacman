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
    window.create(sf::VideoMode(720, 580), "Menu");
    window.setFramerateLimit(60);

    const std::vector<std::string>textureFileNames = {"ressources/Pac-Man_Sprite_Sheet.png"};

    for (auto it: textureFileNames) {
        sf::Texture t;

        // Need to check load success
        t.loadFromFile(it);
        textures.push_back(t);
    }

    currentScene = std::make_unique<GameScene>(textures.front());
}
#include "Button.h"
void Core::loop() {
    sf::Font f;
    f.loadFromFile("ressources/arial.ttf");

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
        currentScene->update(event, window);

        // Clear the whole window before rendering a new frame
        window.clear();

        // Draw entities
        currentScene->draw(window);
        // End the current frame and display its contents on screen
        window.display();
    }
}