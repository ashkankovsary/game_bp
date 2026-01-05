#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"

#define MOVE_SPEED 90.0f
#define ROT_SPEED 5.0f

// map value
#define player_size 7.0f
#define player_color CLITERAL(Color){ 230, 41, 55, 255}
#define player_dir_color CLITERAL(Color){ 0, 121, 241, 255}

// mini map value
#define mini_player_size 2.5f
#define mini_player_color CLITERAL(Color){ 230, 41, 55, 180}
#define mini_player_dir_color CLITERAL(Color){ 0, 121, 241, 180}

typedef struct
{
    Vector2 pos;
    Vector2 dir;
    Vector2 plane;
} Player;

void DrawPlayer(Player player1);
void DrawMiniPlayer(Player player1);
Player MovementForward(Player player1, float dt);
Player MovementBackward(Player player1, float dt);
Player MovementRight(Player player1, float dt);
Player MovementLeft(Player player1, float dt);
Player MovementCounterclockWise(Player player1, float dt);
Player MovementClockWise(Player player1, float dt);
Player CheckWallSliding(Player player1, float new_x, float new_y);

#endif