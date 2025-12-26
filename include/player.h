#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"

typedef struct
{
    Vector2 pos;
    Vector2 dir;
} Player;

void draw_player(Vector2 player_pos, Vector2 player_dir);
Player movement_forward(Player player1, float dt);
Player movement_backward(Player player1, float dt);
Player movement_right(Player player1, float dt);
Player movement_left(Player player1, float dt);
#endif