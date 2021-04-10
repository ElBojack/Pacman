#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/ConvexShape.hpp>

namespace state {
    enum {
        none = 0,
        hovered = 1,
        clicked = 2
    };
};

class Button: public sf::Drawable {
    public:
        // Constructor / Destructor
        Button();
        Button(std::string s, sf::Font &f, sf::Vector2f p);
        ~Button();
        // Setter

        // Getter
        sf::Uint32 getState() const;
        // Other
        void update(sf::Event &, sf::RenderWindow &);

    protected:

    private:
        virtual void draw (sf::RenderTarget &target, sf::RenderStates states) const;

        // Colors
        sf::Color textColor;
        sf::Color BgNoneColor;
        sf::Color BgHoveredColor;
        sf::Color BgClickedColor;
        sf::Color BgBorder;
        
        // State
        sf::Uint32 state;
        
        // Text & Font
        sf::Text text;
        sf::Font font;
        //sf::Uint32 fontSize; // Unused
        
        // Button transform
        sf::ConvexShape shape;
        sf::Vector2f size;
        sf::Vector2f position;

        //Other
        float borderThickness;
        float hide;
        float disable;
};

#endif