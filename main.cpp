// #include "tictactoe.h"

#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML Works!", Style::Titlebar | Style::Close);
    RectangleShape squares[9];

    for (int i = 0; i < 9; i++)
    {
        squares[i].setSize(Vector2f(100.f, 100.f));

        float x = squares[i].getSize().x;
        float y = squares[i].getSize().y;
        squares[i].setPosition(x + ((i % 3) * x), y + ((i / 3) * y));

        squares[i].setOutlineColor(Color::Red);
        squares[i].setOutlineThickness(10.f);
        squares[i].setFillColor(Color::Yellow);
    }

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        for (auto& square : squares)
            window.draw(square);
        window.display();
    }

    return 0;
}