#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "raylib.h"
#include "map.h"
#include "player.h"
#include "raycaster.h"

int world_map[map_h][map_w] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void WriteTextMap(const char *text)
{
    DrawText(text, 10, 10, 20, text_map_and_camera);
}

void DrawLines(int tile_size, int offset_w, int offset_h, Color line_color)
{
    for (int i = 0; i <= map_h; i++)
    {
        DrawLine(offset_w, i * tile_size + offset_h, tile_size * map_w + offset_w, i * tile_size + offset_h, line_color);
    }
    for (int i = 0; i <= map_w; i++)
    {
        DrawLine(i * tile_size + offset_w, offset_h, i * tile_size + offset_w, tile_size * map_h + offset_h, line_color);
    }
}

void DrawMap(int tile_size, int offset_w, int offset_h, Color wallcolor, Color bg_color, Color line_color)
{
    for (int i = 0; i < map_h; i++)
    {
        for (int j = 0; j < map_w; j++)
        {
            if (world_map[i][j] == ROCKY_WALL)
            {
                DrawRectangle(j * tile_size + offset_w, i * tile_size + offset_h, tile_size, tile_size, wallcolor);
            }
            else if(world_map[i][j] == FREE_SPACE)
            {
                DrawRectangle(j * tile_size + offset_w, i * tile_size + offset_h, tile_size, tile_size, bg_color);
            }
        }
    }
    DrawLines(tile_size, offset_w, offset_h, line_color);
}

int TileHoverY()
{
    return floor((float)(GetMouseY() - map_offset_h) / TILE_SIZE);
}

int TileHoverX()
{
    return floor((float)(GetMouseX() - map_offset_w) / TILE_SIZE);
}

bool MouseInMap()
{
    if (TileHoverX() >= 0 && TileHoverX() < map_w && TileHoverY() >= 0 && TileHoverY() < map_h)
        return true;
    return false;
}

void MouseHover(){
    DrawRectangle(TileHoverX()*TILE_SIZE + map_offset_w,TileHoverY()*TILE_SIZE+map_offset_h,TILE_SIZE,TILE_SIZE,tile_hover);
}
