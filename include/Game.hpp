#ifndef GAME_HPP
#define GAME_HPP

#include "Render.hpp"
#include <iostream>

class Game {
    public:
        Game();
        ~Game();

        void update(void);

    private:
        sf::Clock clock;
};

#endif // GAME_HPP