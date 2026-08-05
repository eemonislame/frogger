/*
  this file only gets updated after we both agrees that the chage shoulb be made, other wise not.

  you can update the code in your own file frogger_yourname.c , other user will review it and decide whether it's perfect or not.

*/


#include "raylib.h"

int main(void)
{
    int gw=1200, gh=800;
    InitWindow(gw, gh, "Game");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(YELLOW);
        EndDrawing();
    }

    

    CloseWindow();

    return 0;
}

