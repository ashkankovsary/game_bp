#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"

typedef struct
{
    Vector2 pos;
    Vector2 dir;
    Vector2 plane;
} Player;

void draw_player(Vector2 player_pos, Vector2 player_dir);
Player movement_forward(Player player1, float dt);
Player movement_backward(Player player1, float dt);
Player movement_right(Player player1, float dt);
Player movement_left(Player player1, float dt);
Player movement_counterclock_wise(Player player1, float dt);
Player movement_clock_wise(Player player1, float dt);

#endif