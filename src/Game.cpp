#include "../include/Game.hpp"

Game::Game() {

}

Game::~Game() {

}

void Game::update(void) {
    if (this->clock.getElapsedTime().asMilliseconds() >= 200) {
        std::cout << "Snake moves" << std::endl;
        this->clock.restart();
    }
}