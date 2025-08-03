#ifndef GAME_HPP
#define GAME_HPP

#include "SnakeBody.hpp"

#include <iostream>
#include <vector>
#include <deque>
#include <random>
#include <ctime>
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
        void spawnFood(void);

        bool checkWallCollision(void);
        void checkEatsFood(void);

        bool update(Direction direction);
        void updateMap(void);

        std::vector<std::vector<TileType>> map;
        sf::Vector2i foodPosition;
        std::mt19937 rng;
        std::uniform_int_distribution<int> distX;
        std::uniform_int_distribution<int> distY;
    private:
        sf::Clock clock;
        SnakeBody snake;
};

#endif // GAME_HPP