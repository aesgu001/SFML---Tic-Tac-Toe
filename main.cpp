#include "game.h"

int main()
{
    // initialize game
    Game game;

    // check if game data successfully loaded
    if (!game.loaded())
    {
        std::cerr << "Failed to load game data!" << std::endl
            << "Press any key and ENTER to exit..." << std::endl;
        std::cin.get();
        return 1;
    }

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