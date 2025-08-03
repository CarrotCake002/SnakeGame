#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "Game.hpp"

struct SnakeTextures {
    sf::Texture snakeHead;
    sf::Texture snakeStraightBody;
    sf::Texture snakeRightBody;
    sf::Texture snakeLeftBody;
    sf::Texture snakeTail;
};

class Render {
    public:
        Render(sf::RenderWindow *window);
        ~Render();

        void loadAssets(void);
        void drawBackground(int rowsSize, int colsSize);
        void drawGrid(int rowsSize, int colsSize);
        void drawSnake(void);
        void display(Game *game);
    private:
        sf::Texture grass;
        sf::Texture fruit;
        sf::Texture wall;
        SnakeTextures snakeTextures;
        sf::RenderWindow *window;
};

#endif // RENDERER_HPP