#include "game.h"

int main()
{
    // initialize game
    Game game;

    // game loop
    while (game.running())
    {
        game.update();

        game.render();
    }

    // end of application
    return 0;
}