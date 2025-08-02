#include "../include/SnakeBody.hpp"

SnakeBody::SnakeBody(int cols, int rows) {
    this->snakePosition.push_back(sf::Vector2i(cols, rows));
    this->size = 1;
}

void SnakeBody::move(const Direction dir) {
    sf::Vector2i prevPosition;
    sf::Vector2i nextPosition = this->snakePosition[0];

    switch (dir) {
        case Direction::Up:
            this->snakePosition[0].x -= 1;
            break;
        case Direction::Down:
            this->snakePosition[0].x += 1;
            break;
        case Direction::Left:
            this->snakePosition[0].y -= 1;
            break;
        case Direction::Right:
            this->snakePosition[0].y += 1;
            break;
    }
}

sf::Vector2i SnakeBody::getSnakeSegment(int segment) {
    return this->snakePosition[segment];
}

sf::Vector2i SnakeBody::getHead(void) {
    return this->snakePosition[0];
}

int SnakeBody::getSize(void) {
    return this->size;
}