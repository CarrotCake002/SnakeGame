#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Render.hpp"
#include "Game.hpp"
#include <iostream>

class Snake {
    public:
        Snake();
        ~Snake();

        void handleKeyPress(sf::Event event);
        void run();
    
    private:
        Render *renderer;
        sf::RenderWindow *window;
        Game *game;
        Direction snakeDirection;
};

#endif // SNAKE_HPP