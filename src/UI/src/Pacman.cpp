#include "Pacman.h"

Pacman::Pacman(): state(PacmanState::Right), phase(PacmanPhase::Tic) {
    
}
#include <iostream>
Pacman::Pacman(sf::Texture &t): state(PacmanState::Right), phase(PacmanPhase::Tic) {
    sprite.setTexture(t);

    // Default values
    //sf::IntRect defaultTextureIntRect = sf::IntRect(20, 1, 12, 13);   // Default TextureRect

    sprite.setTextureRect(TEXTUREINTRECT[state]);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setScale(720 / 10 / sprite.getLocalBounds().width, 580 / 10 / sprite.getLocalBounds().height);
    sprite.setPosition(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
}

void Pacman::update(sf::Event &event, sf::RenderWindow &window) {
    // Set state according to key pressed
    if (event.type == sf::Event::EventType::KeyPressed) {
        switch (event.key.code)
        {
        case sf::Keyboard::Key::Up :
            phase = (state != PacmanState::Up) ? PacmanPhase::Tac : phase;
            state = PacmanState::Up;
            break;
        case sf::Keyboard::Key::Down :
            phase = (state != PacmanState::Down) ? PacmanPhase::Tac : phase;
            state = PacmanState::Down;
            break;
        case sf::Keyboard::Key::Left :
            phase = (state != PacmanState::Left) ? PacmanPhase::Tac : phase;
            state = PacmanState::Left;
            break;
        case sf::Keyboard::Key::Right :
            phase = (state != PacmanState::Right) ? PacmanPhase::Tac : phase;
            state = PacmanState::Right;
            break;
        default:
            break;
        }
    }


    // Setup sprite Animation
    if (animationClock.getElapsedTime().asSeconds() >= .25f) {
        if (phase == PacmanPhase::Tic) {
            phase = PacmanPhase::Tac;
            sprite.setTextureRect(TICTACRECT);
        } else {
            phase = PacmanPhase::Tic;
            sprite.setTextureRect(TEXTUREINTRECT[state]);
        }
        animationClock.restart();
    }

    // Movement
    // Prevent Out of Window

    sf::Vector2f next = sprite.getPosition() - sf::Vector2f(sprite.getGlobalBounds().width / 2.f, sprite.getGlobalBounds().height / 2.f);
    bool shouldMove = false;

    switch (state)
    {
    case PacmanState::Up:
        {   
            next += MOVEMENT[state];
            shouldMove = (next.y < 0) ? false : true;
        }
        break;
    case PacmanState::Left:
        {
            next += MOVEMENT[state];
            shouldMove = (next.x < 0) ? false : true;
        }
        break;
    case PacmanState::Right:
        {
            next += MOVEMENT[state];
            shouldMove = (next.x > window.getSize().x  - sprite.getGlobalBounds().width) ? false : true;
        }
        break;
    case PacmanState::Down:
        {
            next += MOVEMENT[state];
            shouldMove = (next.y > window.getSize().y - sprite.getGlobalBounds().height) ? false : true;
        }
        break;    
    default:
        break;
    }
    
    if (shouldMove)
        sprite.setPosition(sprite.getPosition() + MOVEMENT[state]);
}

void Pacman::draw (sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(sprite);
}