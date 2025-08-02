#include "../include/Snake.hpp"

Snake::Snake(void) {
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Snake");
    this->renderer = new Render(window);
    this->game = new Game();
}

Snake::~Snake(void) {
    delete this->window;
    delete this->game;
    delete this->renderer;
}

void Snake::run(void) {
    sf::Event event;

    while (this->window->isOpen()) {
        while (this->window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                this->window->close();
            this->game->update();
            this->renderer->display();
        }
    }
}