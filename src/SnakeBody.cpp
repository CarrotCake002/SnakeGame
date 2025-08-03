#include "../include/SnakeBody.hpp"

SnakeBody::SnakeBody(int cols, int rows) {
    this->snakePosition.push_back(sf::Vector2i(cols, rows));
    this->size = 1;
}

bool SnakeBody::checkDirectionOverlap(const Direction dir) {
    if ((dir == Direction::Up && this->prevDirection == Direction::Down)
    || (dir == Direction::Down && this->prevDirection == Direction::Up)
    || (dir == Direction::Right && this->prevDirection == Direction::Left)
    || (dir == Direction::Left && this->prevDirection == Direction::Right))
        return true;
    return false;
}

void SnakeBody::move(const Direction dir) {
    sf::Vector2i prevSegmentPos = this->snakePosition[0];
    sf::Vector2i nextSegmentPos;

    if (!checkDirectionOverlap(dir)) {
        this->snakePosition[0] += directionOffsets[dir];
        this->prevDirection = dir;
    } else {
        this->snakePosition[0] += directionOffsets[this->prevDirection];
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