#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Graphics.hpp>
#include <memory>

class Render {
    public:
        Render(sf::RenderWindow *window);
        ~Render();

        void display();
    private:
        sf::RenderWindow *window;
};

#endif // RENDERER_HPP