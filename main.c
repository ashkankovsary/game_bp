#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "raylib.h"
#include "map.h"
#include "player.h"
#include "raycaster.h"

#define bg_1 CLITERAL(Color){180, 180, 180, 255}

int main()
{
    InitWindow(700, 700, "Raycaster");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(bg_1);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}