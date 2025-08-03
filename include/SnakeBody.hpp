#ifndef SNAKEBODY_HPP
#define SNAKEBODY_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <deque>
#include <array>

enum Direction {
    Up = 0,
    Down = 1,
    Right = 2,
    Left = 3
};

static const std::array<sf::Vector2i, 4> directionOffsets = {
    sf::Vector2i(-1, 0),  // Up
    sf::Vector2i(1, 0),   // Down
    sf::Vector2i(0, 1),   // Right
    sf::Vector2i(0, -1)   // Left
};

class SnakeBody {
    public:
        SnakeBody(int cols, int rows);
        ~SnakeBody() = default;

        void move(const Direction direction);
        void increaseSize(void);

        bool checkDirectionOverlap(const Direction dir);
        void setDirection(const Direction direction);
        Direction getDirection(void);

        sf::Vector2i getHead(void);
        int getSize(void);
        sf::Vector2i getSnakeSegment(int segment);
    
    private:
        std::deque<sf::Vector2i> snakePosition;
        sf::Vector2i prevTailPosition;
        Direction direction;
        Direction prevDirection;
        int size;
};

#endif // SNAKEBODY_HPP