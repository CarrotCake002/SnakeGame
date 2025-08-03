#include "../include/SnakeBody.hpp"

SnakeBody::SnakeBody(int cols, int rows) {
    this->snakePosition.push_back(sf::Vector2i(cols, rows));
    this->size = 1;
}

void SnakeBody::move(const Direction dir) {
    sf::Vector2i prevSegmentPos = this->snakePosition[0];
    sf::Vector2i nextSegmentPos;
    this->prevTailPosition = this->snakePosition[this->snakePosition.size() - 1];

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
    for (int i = 1; i < this->snakePosition.size(); i++) {
        nextSegmentPos = this->snakePosition[i];
        this->snakePosition[i] = prevSegmentPos;
        prevSegmentPos = nextSegmentPos;
    }
}

void SnakeBody::increaseSize(void) {
    this->snakePosition.push_back(sf::Vector2i(0, 0));
    this->size += 1;
}

void SnakeBody::setDirection(Direction dir) {
    this->direction = dir;
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