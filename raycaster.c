#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "raylib.h"
#include "map.h"
#include "player.h"
#include "raycaster.h"

bool hit;
int side, hit_wall;
float cameraX, distance, lineHeight, drawStart;
intarray2 map, step;
Vector2 raydir, deltadiset, sidedist;

void Raycasting(Player player)
{
    for (int x = 0; x < w_page; x++)
    {
        cameraX = 2 * x / (float)w_page - 1;
        raydir.x = player.dir.x + player.plane.x * cameraX;
        raydir.y = player.dir.y + player.plane.y * cameraX;
        map.x = TilePlayerX(player.pos.x);
        map.y = TilePlayerY(player.pos.y);
        deltadiset.x = (raydir.x == 0) ? 1e30 : fabs(1 / raydir.x);
        deltadiset.y = (raydir.y == 0) ? 1e30 : fabs(1 / raydir.y);
        if (raydir.x < 0)
        {
            step.x = -1;
            sidedist.x = ((float)((player.pos.x - map_offset_w) - map.x * TILE_SIZE) / TILE_SIZE) * deltadiset.x;
        }
        else
        {
            step.x = 1;
            sidedist.x = ((float)((map.x + 1) * TILE_SIZE - (player.pos.x - map_offset_w)) / TILE_SIZE) * deltadiset.x;
        }
        if (raydir.y < 0)
        {
            step.y = -1;
            sidedist.y = ((float)((player.pos.y - map_offset_h) - map.y * TILE_SIZE) / TILE_SIZE) * deltadiset.y;
        }
        else
        {
            step.y = 1;
            sidedist.y = ((float)((map.y + 1) * TILE_SIZE - (player.pos.y - map_offset_h)) / TILE_SIZE) * deltadiset.y;
        }
        hit = false;
        while (!hit)
        {
            if (sidedist.x < sidedist.y)
            {
                sidedist.x += deltadiset.x;
                map.x += step.x;
                side = 0;
            }
            else
            {
                sidedist.y += deltadiset.y;
                map.y += step.y;
                side = 1;
            }
            if (world_map[map.y][map.x] > FREE_SPACE)
            {
                hit_wall = world_map[map.y][map.x];
                hit = true;
            }
        }
        if (side)
            distance = sidedist.y - deltadiset.y;
        else
            distance = sidedist.x - deltadiset.x;
        lineHeight = (distance > 1) ? h_page / distance : h_page;
        drawStart = -lineHeight / 2 + h_page / 2;
        DrawRectangleV((Vector2){x, 0}, (Vector2){1, drawStart}, sky_color);
        if (hit_wall == ROCKY_WALL)
            DrawRectangleV((Vector2){x, drawStart}, (Vector2){1, lineHeight}, CLITERAL(Color){50 + side * 20, 50 + side * 20, 50 + side * 20, 255});
        DrawRectangleV((Vector2){x, drawStart + lineHeight}, (Vector2){1, h_page - (drawStart + lineHeight)}, ground_color);
    }
}