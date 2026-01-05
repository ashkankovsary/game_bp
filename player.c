#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "raylib.h"
#include "map.h"
#include "player.h"
#include "raycaster.h"

void draw_player(Vector2 player_pos, Vector2 player_dir)
{
    DrawCircleV(player_pos, player_size, RED);
    DrawLineV(player_pos, (Vector2){player_pos.x + player_dir.x * 20, player_pos.y + player_dir.y * 20}, BLUE);
}
Player check_wall_sliding(Player player1, float new_x, float new_y){
    int tileX = (int)((new_x - space) / TILE_SIZE);
    int tileY = (int)((new_y - space) / TILE_SIZE);
    if(world_map[(int)((player1.pos.y - space) / TILE_SIZE)][tileX] == 0)
        player1.pos.x = new_x;
    if(world_map[tileY][(int)((player1.pos.x - space) / TILE_SIZE)] == 0)
        player1.pos.y = new_y;
    return player1;
}
Player movement_forward(Player player1, float dt)
{
    float new_x = player1.pos.x + player1.dir.x * MOVE_SPEED * dt;
    float new_y = player1.pos.y + player1.dir.y * MOVE_SPEED * dt;
    return check_wall_sliding(player1, new_x, new_y);
}
Player movement_backward(Player player1, float dt)
{
    float new_x = player1.pos.x - player1.dir.x * MOVE_SPEED * dt;
    float new_y = player1.pos.y - player1.dir.y * MOVE_SPEED * dt;
    return check_wall_sliding(player1, new_x, new_y);
}
Player movement_right(Player player1, float dt)
{
    float new_x = player1.pos.x - player1.dir.y * MOVE_SPEED * dt * 0.8;
    float new_y = player1.pos.y + player1.dir.x * MOVE_SPEED * dt * 0.8;
    return check_wall_sliding(player1, new_x, new_y);
}
Player movement_left(Player player1, float dt)
{
    float new_x = player1.pos.x + player1.dir.y * MOVE_SPEED * dt * 0.8;
    float new_y = player1.pos.y - player1.dir.x * MOVE_SPEED * dt * 0.8;
    return check_wall_sliding(player1, new_x, new_y);
}
Player movement_counterclock_wise(Player player1, float dt)
{
    float oldDirX = player1.dir.x;
    player1.dir.x = player1.dir.x * cos(-ROT_SPEED * dt) - player1.dir.y * sin(-ROT_SPEED * dt);
    player1.dir.y = oldDirX * sin(-ROT_SPEED * dt) + player1.dir.y * cos(-ROT_SPEED * dt);

    float oldPlaneX = player1.plane.x;
    player1.plane.x = player1.plane.x * cos(-ROT_SPEED * dt) - player1.plane.y * sin(-ROT_SPEED * dt);
    player1.plane.y = oldPlaneX * sin(-ROT_SPEED * dt) + player1.plane.y * cos(-ROT_SPEED * dt);
    return player1;
}
Player movement_clock_wise(Player player1, float dt)
{
    float oldDirX = player1.dir.x;
    player1.dir.x = player1.dir.x * cos(ROT_SPEED * dt) - player1.dir.y * sin(ROT_SPEED * dt);
    player1.dir.y = oldDirX * sin(ROT_SPEED * dt) + player1.dir.y * cos(ROT_SPEED * dt);

    float oldPlaneX = player1.plane.x;
    player1.plane.x = player1.plane.x * cos(ROT_SPEED * dt) - player1.plane.y * sin(ROT_SPEED * dt);
    player1.plane.y = oldPlaneX * sin(ROT_SPEED * dt) + player1.plane.y * cos(ROT_SPEED * dt);
    return player1;
}