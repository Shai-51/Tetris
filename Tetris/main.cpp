#include <raylib.h>
#include "Game.h"

int main(int argc, char* argv[]) {

    InitWindow(300, 600, "tetris");
    SetTargetFPS(60);
    Game game = Game();

    while (WindowShouldClose() == false)
    {
        game.Run();
    }

    CloseWindow();
}