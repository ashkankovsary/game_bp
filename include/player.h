#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"

#define player_size 7.0f
#define MOVE_SPEED 90.0f
#define ROT_SPEED 5.0f

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
Player check_wall_sliding(Player player1, float new_x, float new_y);

#endif