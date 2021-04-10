#include "Button.h"

#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>

Button::Button() {

}

Button::Button(std::string s, sf::Font &f, sf::Vector2f p /* top left position */) {
    text = sf::Text();
    font = f;
    position = p;

    // Set default values for attributes
    text.setString(s);
    state = state::none;
    textColor = sf::Color(23, 32, 42);
    BgNoneColor = sf::Color(213, 219, 219);
    BgHoveredColor = sf::Color(191, 201, 202);
    BgClickedColor = sf::Color(170, 183, 184);
    BgBorder = sf::Color(149, 165, 166);
    borderThickness = 1.f;

    hide = false;
    disable = false;

    // Set size according to text size
    text.setFont(font);
    text.setOrigin(text.getGlobalBounds().width / 2,text.getGlobalBounds().height / 2);
    size = sf::Vector2f(text.getGlobalBounds().width * 1.5f, text.getGlobalBounds().height * 1.5f);

    // Define default shape
    shape = sf::ConvexShape();

    shape.setPointCount(4);
    shape.setPoint(0, sf::Vector2f(0, 0));
    shape.setPoint(1, sf::Vector2f(size.x, 0));
    shape.setPoint(2, sf::Vector2f(size));
    shape.setPoint(3, sf::Vector2f(0, size.y));
    shape.setOutlineThickness(borderThickness);

    shape.setOrigin(shape.getGlobalBounds().width / 2,shape.getGlobalBounds().height / 2);
    shape.setPosition(position);

    text.setPosition(sf::Vector2f(
        shape.getPosition().x,
        shape.getPosition().y - shape.getGlobalBounds().height / 4
    ));

    // Apply Color to element
    text.setFillColor(textColor);
    shape.setFillColor(BgNoneColor);
    shape.setOutlineColor(BgBorder);
}

void Button::update(sf::Event &event, sf::RenderWindow &window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    bool isOnButton = mousePosition.x >= shape.getPosition().x - shape.getGlobalBounds().width/2
                    && mousePosition.x <= shape.getPosition().x + shape.getGlobalBounds().width/2
                    && mousePosition.y >= shape.getPosition().y - shape.getGlobalBounds().height/2
                    && mousePosition.y <= shape.getPosition().y + shape.getGlobalBounds().height/2;

    /**
     * Style settings 
     **/
    if (event.type == sf::Event::EventType::MouseMoved) {
        if (isOnButton) {
            state = state::hovered;
        } else {
            state = state::none;
        }
    }

    if (event.type == sf::Event::EventType::MouseButtonPressed) {
        switch(event.mouseButton.button)
        {
            case sf::Mouse::Left:
            {
                if(isOnButton)
                {
                   state = state::clicked;
                }
                else
                {
                   state = state::none;
                }
            }
            break;
        }
    }

    if (event.type == sf::Event::EventType::MouseButtonReleased)
    {
        switch(event.mouseButton.button)
        {
            case sf::Mouse::Left:
            {
                if(isOnButton)
                {
                    state = state::hovered;
                }
                else
                {
                    state = state::none;
                }
            }
            break;
        }
    }

    switch (state)
    {
    case state::none :
        {
            shape.setFillColor(BgNoneColor);
        }
        break;
    case state::hovered:
        {
            shape.setFillColor(BgHoveredColor);
        }
        break;
    case state::clicked:
        {
            shape.setFillColor(BgClickedColor);
        }
        break;
    default:
        break;
    }

    /**
     *  Action to do onClick
     **/
}

// Getter
sf::Uint32 Button::getState() const {
    return (state);
}

// private
void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (hide)
        return;
    target.draw(shape);
    target.draw(text);
}

// Clean
Button::~Button() {

}
