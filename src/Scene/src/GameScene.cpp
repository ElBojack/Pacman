#include "GameScene.h"

GameScene::GameScene(sf::Texture &texture) {
    load(texture);
    // Do something if fail
    // operator == and =! necessary (Error class)
}

Error GameScene::load(sf::Texture &texture) {
    pacman = Pacman(texture);

    return ErrorNone();
}

void GameScene::update(sf::Event &event, sf::RenderWindow &window) {
    pacman.update(event, window);
}

void GameScene::draw(sf::RenderWindow &window) {
    window.draw(pacman);
}