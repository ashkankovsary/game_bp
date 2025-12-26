#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "raylib.h"
#include "player.h"

#define player_size 7.0f
#define MOVE_SPEED 90.0f

void draw_player(Vector2 player_pos, Vector2 player_dir)
{
    DrawCircleV(player_pos, player_size, RED);
    DrawLineV(player_pos, (Vector2){player_pos.x + player_dir.x * 20, player_pos.y + player_dir.y * 20}, BLUE);
}
Player movement_forward(Player player1, float dt)
{
    player1.pos.x += MOVE_SPEED * dt;
    return player1;
}
Player movement_backward(Player player1, float dt)
{
    player1.pos.x -= MOVE_SPEED * dt;
    return player1;
}
Player movement_right(Player player1, float dt)
{
    player1.pos.y += MOVE_SPEED * dt * 0.7;
    return player1;
}
Player movement_left(Player player1, float dt)
{
    player1.pos.y -= MOVE_SPEED * dt * 0.7;
    return player1;
}