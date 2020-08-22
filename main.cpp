#include "game.h"

int main()
{
    // initialize game
    Game game;

    // game loop
    while (game.running())
    {
        // update frame
        game.update();

        // render frame
        game.render();
    }

    // end of application
    return 0;
}