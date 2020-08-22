#include "game.h"

int main()
{
    // initialize game
    Game game;

    // game loop
    while (game.running())
    {
        // update game
        game.update();

        // render game
        game.render();
    }

    // end of application
    return 0;
}