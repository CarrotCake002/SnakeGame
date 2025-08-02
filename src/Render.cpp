#include "../include/Render.hpp"

Render::Render(sf::RenderWindow *window) {
    this->window = window;
}

Render::~Render() {

}

void Render::display(Game *game) {
    for (int i; i < game->map.size(); i++) {
        for (int j; j < game->map[i].size(); i++) {
            std::cout << game->map[i][j];
        }
        std::cout << std::endl;
    }
    //window->clear(sf::Color::Black);
    //window->display();
}