#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "raylib.h"
#include "map.h"
#include "player.h"
#include "raycaster.h"

bool hit;
int side, lineHeight, drawStart, drawEnd;
float cameraX, distance;
intarray2 map, step;
Vector2 raydir, deltadiset, sidedist;

void raycasting(Player player1)
{
    for (int x = 0; x < w_page; x++)
    {
        cameraX = 2 * x / (float)w_page - 1;
        raydir.x = player1.dir.x + player1.plane.x * cameraX;
        raydir.y = player1.dir.y + player1.plane.y * cameraX;
        map.x = (int)(player1.pos.x - space) / TILE_SIZE;
        map.y = (int)(player1.pos.y - space) / TILE_SIZE;
        deltadiset.x = (raydir.x == 0) ? 1e30 : fabs(1 / raydir.x);
        deltadiset.y = (raydir.y == 0) ? 1e30 : fabs(1 / raydir.y);
        if (raydir.x < 0)
        {
            step.x = -1;
            sidedist.x = ((float)(player1.pos.x - map.x * TILE_SIZE) / TILE_SIZE) * deltadiset.x;
        }
        else
        {
            step.x = 1;
            sidedist.x = ((float)(player1.pos.x - map.x * TILE_SIZE) / TILE_SIZE) * deltadiset.x;
        }
        if (raydir.y < 0)
        {
            step.y = -1;
            sidedist.y = ((float)(player1.pos.y - map.y * TILE_SIZE) / TILE_SIZE) * deltadiset.y;
        }
        else
        {
            step.y = 1;
            sidedist.y = ((float)(player1.pos.y - map.y * TILE_SIZE) / TILE_SIZE) * deltadiset.y;
        }
        hit = false;
        while (hit)
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
            if (world_map[map.y][map.x] > 0)
                hit = true;
        }
    }
}