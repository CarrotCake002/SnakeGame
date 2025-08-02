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
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::W:
                this->snakeDirection = Direction::Up;
                break;
            case sf::Keyboard::S:
                this->snakeDirection = Direction::Down;
                break;
            case sf::Keyboard::A:
                this->snakeDirection = Direction::Left;
                break;
            case sf::Keyboard::D:
                this->snakeDirection = Direction::Right;
                break;
        }
    }
}

void Snake::run(void) {
    sf::Event event;
    Direction dir;
    bool runGame = true;

    this->game->displayMapInTerminal();

    while (this->window->isOpen()) {
        while (this->window->pollEvent(event)) {
            this->handleKeyPress(event);
        }
        if (!this->game->update(this->snakeDirection))
            this->window->close();
        this->renderer->display(this->game);
    }
}