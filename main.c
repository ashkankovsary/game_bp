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
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(700, 700, "Raycaster");
    Player player1;
    player1.pos = (Vector2){100.0f, 100.0f};
    player1.dir = (Vector2){1.0f, 0.0f};
    player1.plane = (Vector2){0.0f, 0.66f};
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        if (IsKeyDown(KEY_W))
            player1 = movement_forward(player1, dt);
        if (IsKeyDown(KEY_S))
            player1 = movement_backward(player1, dt);
        if (IsKeyDown(KEY_D))
            player1 = movement_right(player1, dt);
        if (IsKeyDown(KEY_A))
            player1 = movement_left(player1, dt);
        if (IsKeyDown(KEY_LEFT))
            player1 = movement_counterclock_wise(player1, dt);
        if (IsKeyDown(KEY_RIGHT))
            player1 = movement_clock_wise(player1, dt);
        BeginDrawing();
        ClearBackground(bg_1);
        DrawMap();
        draw_player(player1.pos, player1.dir);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}