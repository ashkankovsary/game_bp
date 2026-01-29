#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "raylib.h"
#include "map.h"
#include "player.h"
#include "raycaster.h"

int main()
{
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(w_page, h_page, "Raycaster");
    Player player1;
    player1.pos = (Vector2){100.0f, 100.0f};
    player1.dir = (Vector2){1.0f, 0.0f};
    player1.plane = (Vector2){0.0f, 0.66f};
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        if (IsKeyDown(KEY_W))
            player1.pos = MovementForward(player1, dt);
        if (IsKeyDown(KEY_S))
            player1.pos = MovementBackward(player1, dt);
        if (IsKeyDown(KEY_D))
            player1.pos = MovementRight(player1, dt);
        if (IsKeyDown(KEY_A))
            player1.pos = MovementLeft(player1, dt);
        if (IsKeyDown(KEY_LEFT))
            player1 = MovementCounterclockWise(player1, dt);
        if (IsKeyDown(KEY_RIGHT))
            player1 = MovementClockWise(player1, dt);
        BeginDrawing();
        ClearBackground(WHITE);
        Raycasting(player1);
        DrawMap(mini_tile_size, mini_map_offset_w, mini_map_offset_h, mini_wall_color, mini_bg_map, mini_map_line_color);
        DrawMiniPlayer(player1);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}