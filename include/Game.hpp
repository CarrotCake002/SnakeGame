#ifndef GAME_HPP
#define GAME_HPP

#include "SnakeBody.hpp"

#include <iostream>
#include <vector>
#include <deque>
#include <SFML/Graphics.hpp>

enum TileType {
    EmptyTile,
    Wall,
    Food,
    SnakeHead,
    SnakeTorso,
    SnakeTail
};

class Game {
    public:
        Game(int cols, int rows);
        ~Game();

        void resetMap();
        void displayMapInTerminal(void);

        void update(Direction direction);
        void updateMap(void);

        std::vector<std::vector<TileType>> map;
    private:
        sf::Clock clock;
        SnakeBody snake;
};

#endif // GAME_HPP