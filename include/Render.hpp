#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "Game.hpp"

class Render {
    public:
        Render(sf::RenderWindow *window);
        ~Render();

        void display(Game *game);
    private:
        sf::RenderWindow *window;
};

#endif // RENDERER_HPP