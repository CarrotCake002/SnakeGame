#include "../include/Game.hpp"

Game::Game(int cols, int rows)
    :   map(rows, std::vector<TileType>(cols, TileType::EmptyTile)),
        snake((cols / 2) - 1, (rows / 2) - 1),
        rng(static_cast<unsigned int>(time(nullptr))),
        distX(1, cols - 2),
        distY(1, rows - 2)
{
    this->resetMap();
    this->spawnFood();
    map[snake.getHead().x][snake.getHead().y] = TileType::SnakeHead;
}

Game::~Game() {

}

void Game::displayMapInTerminal(void) {
    for (int i = 0; i < this->map.size(); i++) {
        for (int j = 0; j < this->map[i].size(); j++) {
            if (this->map[i][j] == TileType::EmptyTile)
                std::cout << "\033[32m" << this->map[i][j] << "\033[0m";
            else if (this->map[i][j] == TileType::Food)
                std::cout << "\033[31m" << this->map[i][j] << "\033[0m";
            else if (this->map[i][j] == TileType::SnakeHead || this->map[i][j] == TileType::SnakeTorso || this->map[i][j] == TileType::SnakeTail)
                std::cout << "\033[33m" << this->map[i][j] << "\033[0m";
            else if (this->map[i][j] == TileType::Wall)
                std::cout << "\033[38;5;130m" << this->map[i][j] << "\033[0m";
            if (j < this->map[i].size() - 1)
                std::cout << "|";
        }
        std::cout << "\n";
    }
}

void Game::resetMap(void) {
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (i == 0 || j == 0 || i == map.size() - 1 || j == map[i].size() - 1)
                map[i][j] = TileType::Wall;
            else if (sf::Vector2i(i, j) == this->foodPosition)
                map[i][j] = TileType::Food;
            else
                map[i][j] = TileType::EmptyTile;
        }
    }
}

void Game::updateMap(void) {
    sf::Vector2i segment;

    this->resetMap();
    std::cout << snake.getSize() << std::endl;
    for (int i = 0; i < this->snake.getSize(); i++) {
        segment = this->snake.getSnakeSegment(i);
        if (i == 0)
            this->map[segment.x][segment.y] = TileType::SnakeHead;
        else if (i != this->snake.getSize() - 1)
            this->map[segment.x][segment.y] = TileType::SnakeTorso;
        else
            this->map[segment.x][segment.y] = TileType::SnakeTail;
    }

}

void Game::spawnFood(void) {
    bool foodPlaced = false;

    while (!foodPlaced) {
        sf::Vector2i newPosition(this->distX(rng), this->distY(rng));
        if (map[newPosition.x][newPosition.y] == TileType::EmptyTile) {
            this->foodPosition = newPosition;
            foodPlaced = true;
        }
    }
}

bool Game::checkWallCollision(void) {
    sf::Vector2i head = this->snake.getHead();
    if (head.x == 0  || head.y == 0 || head.x == this->map.size() - 1 || head.y == this->map[0].size() - 1)
        return true;
    return false;
}

void Game::checkEatsFood(void) {
    if (this->snake.getHead() == this->foodPosition) {
        this->snake.increaseSize();
        this->spawnFood();
    }
}

bool Game::update(Direction direction) {
    if (this->clock.getElapsedTime().asMilliseconds() >= 200) {
        this->snake.setDirection(direction);
        this->snake.move(direction);
        checkEatsFood();
        if (checkWallCollision())
            return false;
        this->updateMap();
        std::cout << std::endl;
        this->displayMapInTerminal();
        this->clock.restart();
    }
    return true;
}