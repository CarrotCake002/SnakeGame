#include "../include/Render.hpp"

Render::Render(sf::RenderWindow *window) {
    this->window = window;
    this->loadAssets();
}

Render::~Render() {

}

void Render::loadAssets(void) {
    if (!this->grass.loadFromFile("../assets/background_grass_light.png")) {}
    if (!this->fruit.loadFromFile("../assets/fruit.png")) {}
    if (!this->wall.loadFromFile("../assets/background_grass_dense.png")) {}
    if (!this->snakeTextures.snakeHead.loadFromFile("../assets/snake_head.png")) {}
    if (!this->snakeTextures.snakeStraightBody.loadFromFile("../assets/snake_body_straight.png")) {}
    if (!this->snakeTextures.snakeLeftBody.loadFromFile("../assets/snake_body_left.png")) {}
    if (!this->snakeTextures.snakeRightBody.loadFromFile("../assets/snake_body_right.png")) {}
    if (!this->snakeTextures.snakeTail.loadFromFile("../assets/snake_tail.png")) {}
}

void Render::drawBackground(int rowsSize, int colsSize) {
    sf::Sprite grassTile;

    this->grass.setSmooth(false);
    grassTile.setTexture(this->grass);

    for (int row = 0; row < rowsSize; row++) {
        for (int col = 0; col < colsSize; col++) {
            grassTile.setPosition(col * 16.0f * 2, row * 16.0f * 2);
            window->draw(grassTile);
        }
    }
}

void Render::drawGrid(int rowSize, int colSize) {
    sf::Color gridColor(100, 100, 100, 100);  // light gray, semi-transparent
    sf::RectangleShape line;

    // Vertical lines
    for (int x = 0; x <= colSize; ++x) {
        line.setSize(sf::Vector2f(1.f, rowSize * 16 * 2));
        line.setPosition(x * 16.f * 2, 0.f);
        line.setFillColor(gridColor);
        window->draw(line);
    }

    // Horizontal lines
    for (int y = 0; y <= rowSize; ++y) {
        line.setSize(sf::Vector2f(colSize * 16 * 2, 1.f));
        line.setPosition(0.f, y * 16.f * 2);
        line.setFillColor(gridColor);
        window->draw(line);
    }
}

void Render::display(Game *game) {
    for (int i; i < game->map.size(); i++) {
        for (int j; j < game->map[i].size(); i++) {
            std::cout << game->map[i][j];
        }
        std::cout << std::endl;
    }
    window->clear(sf::Color::Black);
    this->drawBackground(game->map.size(), game->map[0].size());
    this->drawGrid(game->map.size(), game->map[0].size());
    window->display();
}