#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "raylib.h"
#include "map.h"
#include "player.h"
#include "raycaster.h"

void DrawPlayer(Player player)
{
    DrawCircleV(player.pos, player_size, player_color);
    DrawLineV(player.pos, (Vector2){player.pos.x + player.dir.x * 20, player.pos.y + player.dir.y * 20}, player_dir_color);
}

void DrawMiniPlayer(Player player)
{
    DrawCircleV((Vector2){(player.pos.x - map_offset_w) / 5 + mini_map_offset_w, (player.pos.y - map_offset_h) / 5 + mini_map_offset_h}, mini_player_size, mini_player_color);
    DrawLineV((Vector2){(player.pos.x - map_offset_w) / 5 + mini_map_offset_w, (player.pos.y - map_offset_h) / 5 + mini_map_offset_h}, (Vector2){(player.pos.x - map_offset_w) / 5 + mini_map_offset_w + player.dir.x * 10, (player.pos.y - map_offset_h) / 5 + mini_map_offset_h + player.dir.y * 10}, mini_player_dir_color);
}

int TilePlayerX(int positionX)
{
    return floor((positionX - map_offset_w) / TILE_SIZE);
}

int TilePlayerY(int positionY)
{
    return floor((positionY - map_offset_h) / TILE_SIZE);
}

Vector2 CheckWallSliding(Vector2 position, float new_x, float new_y)
{
    int tileX = (int)((new_x - map_offset_w) / TILE_SIZE);
    int tileY = (int)((new_y - map_offset_h) / TILE_SIZE);
    if (world_map[TilePlayerY(position.y)][tileX] == FREE_SPACE)
        position.x = new_x;
    if (world_map[tileY][TilePlayerX(position.x)] == FREE_SPACE)
        position.y = new_y;
    return position;
}

Vector2 MovementForward(Player player, float dt)
{
    float new_x = player.pos.x + player.dir.x * MOVE_SPEED * dt;
    float new_y = player.pos.y + player.dir.y * MOVE_SPEED * dt;
    return CheckWallSliding(player.pos, new_x, new_y);
}

Vector2 MovementBackward(Player player, float dt)
{
    float new_x = player.pos.x - player.dir.x * MOVE_SPEED * dt;
    float new_y = player.pos.y - player.dir.y * MOVE_SPEED * dt;
    return CheckWallSliding(player.pos, new_x, new_y);
}

Vector2 MovementRight(Player player, float dt)
{
    float new_x = player.pos.x - player.dir.y * MOVE_SPEED * dt * 0.8;
    float new_y = player.pos.y + player.dir.x * MOVE_SPEED * dt * 0.8;
    return CheckWallSliding(player.pos, new_x, new_y);
}

Vector2 MovementLeft(Player player, float dt)
{
    float new_x = player.pos.x + player.dir.y * MOVE_SPEED * dt * 0.8;
    float new_y = player.pos.y - player.dir.x * MOVE_SPEED * dt * 0.8;
    return CheckWallSliding(player.pos, new_x, new_y);
}

Player MovementCounterclockWise(Player player, float dt)
{
    float oldDirX = player.dir.x;
    player.dir.x = player.dir.x * cos(-ROT_SPEED * dt) - player.dir.y * sin(-ROT_SPEED * dt);
    player.dir.y = oldDirX * sin(-ROT_SPEED * dt) + player.dir.y * cos(-ROT_SPEED * dt);

    float oldPlaneX = player.plane.x;
    player.plane.x = player.plane.x * cos(-ROT_SPEED * dt) - player.plane.y * sin(-ROT_SPEED * dt);
    player.plane.y = oldPlaneX * sin(-ROT_SPEED * dt) + player.plane.y * cos(-ROT_SPEED * dt);
    return player;
}

Player MovementClockWise(Player player, float dt)
{
    float oldDirX = player.dir.x;
    player.dir.x = player.dir.x * cos(ROT_SPEED * dt) - player.dir.y * sin(ROT_SPEED * dt);
    player.dir.y = oldDirX * sin(ROT_SPEED * dt) + player.dir.y * cos(ROT_SPEED * dt);

    float oldPlaneX = player.plane.x;
    player.plane.x = player.plane.x * cos(ROT_SPEED * dt) - player.plane.y * sin(ROT_SPEED * dt);
    player.plane.y = oldPlaneX * sin(ROT_SPEED * dt) + player.plane.y * cos(ROT_SPEED * dt);
    return player;
}