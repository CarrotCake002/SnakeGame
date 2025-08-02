#include "../include/Snake.hpp"

int main() {
    Snake *snake = new Snake();

    snake->run();

    delete snake;
    return 0;
}