#include "../include/Render.hpp"

Render::Render(sf::RenderWindow *window) {
    this->window = window;
}

Render::~Render() {

}

void Render::display(void) {
    window->clear(sf::Color::Black);
    window->display();
}