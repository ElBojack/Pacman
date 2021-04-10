#ifndef PACMAN_HPP
#define PACMAN_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Clock.hpp>

namespace PacmanState {
    enum {
        Up = 0,
        Down,
        Left,
        Right
    };
};

namespace PacmanPhase {
    enum {
       Tic = false,
       Tac = true
    };
};

const std::vector<sf::IntRect> TEXTUREINTRECT = {
    sf::IntRect(20, 33, 13, 13),
    sf::IntRect(20, 49, 13, 13),
    sf::IntRect(20, 17, 13, 13),
    sf::IntRect(20, 1, 13, 13)
};

const sf::IntRect TICTACRECT = {
    sf::IntRect(36, 1, 13, 13)
};

const std::vector<sf::Vector2f> MOVEMENT = {
    sf::Vector2f(0, -2),
    sf::Vector2f(0, 2),
    sf::Vector2f(-2, 0),
    sf::Vector2f(2, 0)
};

const std::vector<sf::Vector2f> NOMOVEMENT = {
    sf::Vector2f(0, 0),
    sf::Vector2f(0, 0),
    sf::Vector2f(0, 0),
    sf::Vector2f(0, 0)
};

class Pacman: public sf::Drawable {
    public:
        Pacman();
        Pacman(sf::Texture &);
        ~Pacman() {};

        void update(sf::Event &, sf::RenderWindow &);
    protected:

    private:
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        sf::Sprite sprite;
        sf::Uint32 state;
        bool phase;
        sf::Clock animationClock;
};

#endif