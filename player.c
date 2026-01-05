#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "raylib.h"
#include "map.h"
#include "player.h"
#include "raycaster.h"

void DrawPlayer(Player player1)
{
    DrawCircleV(player1.pos, player_size, player_color);
    DrawLineV(player1.pos, (Vector2){player1.pos.x + player1.dir.x * 20, player1.pos.y + player1.dir.y * 20}, player_dir_color);
}

void DrawMiniPlayer(Player player1)
{
    DrawCircleV((Vector2){(player1.pos.x - map_offset_w)/5 + mini_map_offset_w, (player1.pos.y - map_offset_h)/5 + mini_map_offset_h}, mini_player_size, mini_player_color);
    DrawLineV((Vector2){(player1.pos.x - map_offset_w)/5 + mini_map_offset_w, (player1.pos.y - map_offset_h)/5 + mini_map_offset_h}, (Vector2){(player1.pos.x - map_offset_w)/5 + mini_map_offset_w + player1.dir.x * 10, (player1.pos.y - map_offset_h)/5 + mini_map_offset_h + player1.dir.y * 10}, mini_player_dir_color);
}

Player CheckWallSliding(Player player1, float new_x, float new_y){
    int tileX = (int)((new_x - map_offset_w) / TILE_SIZE);
    int tileY = (int)((new_y - map_offset_h) / TILE_SIZE);
    if(world_map[(int)((player1.pos.y - map_offset_h) / TILE_SIZE)][tileX] == 0)
        player1.pos.x = new_x;
    if(world_map[tileY][(int)((player1.pos.x - map_offset_w) / TILE_SIZE)] == 0)
        player1.pos.y = new_y;
    return player1;
}

Player MovementForward(Player player1, float dt)
{
    float new_x = player1.pos.x + player1.dir.x * MOVE_SPEED * dt;
    float new_y = player1.pos.y + player1.dir.y * MOVE_SPEED * dt;
    return CheckWallSliding(player1, new_x, new_y);
}

Player MovementBackward(Player player1, float dt)
{
    float new_x = player1.pos.x - player1.dir.x * MOVE_SPEED * dt;
    float new_y = player1.pos.y - player1.dir.y * MOVE_SPEED * dt;
    return CheckWallSliding(player1, new_x, new_y);
}

Player MovementRight(Player player1, float dt)
{
    float new_x = player1.pos.x - player1.dir.y * MOVE_SPEED * dt * 0.8;
    float new_y = player1.pos.y + player1.dir.x * MOVE_SPEED * dt * 0.8;
    return CheckWallSliding(player1, new_x, new_y);
}

Player MovementLeft(Player player1, float dt)
{
    float new_x = player1.pos.x + player1.dir.y * MOVE_SPEED * dt * 0.8;
    float new_y = player1.pos.y - player1.dir.x * MOVE_SPEED * dt * 0.8;
    return CheckWallSliding(player1, new_x, new_y);
}

Player MovementCounterclockWise(Player player1, float dt)
{
    float oldDirX = player1.dir.x;
    player1.dir.x = player1.dir.x * cos(-ROT_SPEED * dt) - player1.dir.y * sin(-ROT_SPEED * dt);
    player1.dir.y = oldDirX * sin(-ROT_SPEED * dt) + player1.dir.y * cos(-ROT_SPEED * dt);

    float oldPlaneX = player1.plane.x;
    player1.plane.x = player1.plane.x * cos(-ROT_SPEED * dt) - player1.plane.y * sin(-ROT_SPEED * dt);
    player1.plane.y = oldPlaneX * sin(-ROT_SPEED * dt) + player1.plane.y * cos(-ROT_SPEED * dt);
    return player1;
}

Player MovementClockWise(Player player1, float dt)
{
    float oldDirX = player1.dir.x;
    player1.dir.x = player1.dir.x * cos(ROT_SPEED * dt) - player1.dir.y * sin(ROT_SPEED * dt);
    player1.dir.y = oldDirX * sin(ROT_SPEED * dt) + player1.dir.y * cos(ROT_SPEED * dt);

    float oldPlaneX = player1.plane.x;
    player1.plane.x = player1.plane.x * cos(ROT_SPEED * dt) - player1.plane.y * sin(ROT_SPEED * dt);
    player1.plane.y = oldPlaneX * sin(ROT_SPEED * dt) + player1.plane.y * cos(ROT_SPEED * dt);
    return player1;
}