#ifndef SNAKEBODY_HPP
#define SNAKEBODY_HPP

#include <SFML/Graphics.hpp>
#include <deque>

enum Direction {
    Up,
    Down,
    Right,
    Left
};

class SnakeBody {
    public:
        SnakeBody(int cols, int rows);
        ~SnakeBody() = default;

        void move(const Direction direction);

        void setDirection(Direction direction);

        sf::Vector2i getHead(void);
        Direction getDirection(void);
        int getSize(void);
        sf::Vector2i getSnakeSegment(int segment);
    
    private:
        std::deque<sf::Vector2i> snakePosition;
        Direction direction;
        int size;
};

#endif // SNAKEBODY_HPP