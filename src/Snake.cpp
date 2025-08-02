#include "../include/Snake.hpp"

Snake::Snake(void) {
    int mapX = 20;
    int mapY = 20;

    this->snakeDirection = Direction::Up;
    this->window = new sf::RenderWindow(sf::VideoMode(mapX * 32, mapY * 32), "Snake");
    this->renderer = new Render(window);
    this->game = new Game(mapX, mapY);
}

Snake::~Snake(void) {
    delete this->window;
    delete this->game;
    delete this->renderer;
}

void Snake::handleKeyPress(sf::Event event) {
    if (event.type == sf::Event::Closed)
        this->window->close();
    if (event.type == sf::Event::KeyPressed) { // CHANGE THIS TO ALWAYS UPDATE
        this->game->update(this->snakeDirection);
        this->renderer->display(this->game);
    }
}

void Snake::run(void) {
    sf::Event event;
    Direction dir;

    this->game->displayMapInTerminal();

    while (this->window->isOpen()) {
        while (this->window->pollEvent(event)) {
            this->handleKeyPress(event);
        }
    }
}