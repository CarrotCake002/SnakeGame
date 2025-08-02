#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Render.hpp"
#include "Game.hpp"
#include <iostream>

class Snake {
    public:
        Snake();
        ~Snake();

        void run();
    
    private:
        Render *renderer;
        sf::RenderWindow *window;
        Game *game;
};

#endif // SNAKE_HPP