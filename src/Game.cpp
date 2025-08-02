#include "../include/Game.hpp"

Game::Game(int cols, int rows) :  map(rows, std::vector<TileType>(cols, TileType::EmptyTile)), snake((cols / 2) - 1, (rows / 2) - 1) {
    resetMap();
    map[snake.getHead().x][snake.getHead().y] = TileType::SnakeHead;
}

Game::~Game() {

}

void Game::displayMapInTerminal(void) {
    for (int i = 0; i < this->map.size(); i++) {
        for (int j = 0; j < this->map[i].size(); j++) {
            std::cout << this->map[i][j];
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
            else
                map[i][j] = TileType::EmptyTile;
        }
    }
}

void Game::updateMap(void) {
    sf::Vector2i segment;

    this->resetMap();
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

void Game::update(Direction direction) {
    if (this->clock.getElapsedTime().asMilliseconds() >= 200) {
        this->snake.move(direction);
        this->updateMap();
        std::cout << std::endl;
        this->displayMapInTerminal();
        this->clock.restart();
    }
}