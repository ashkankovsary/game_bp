#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "raylib.h"

#define map_w 20
#define map_h 20
#define TILE_SIZE 35
#define bg_1 CLITERAL(Color){180, 180, 180, 255}
#define map_line_color CLITERAL(Color){ 120, 120, 120, 255 }

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
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void write_text_map(char *text, int posX, int posY, int fontSize, Color color)
{
    DrawText(text, posX, posY, fontSize, color);
}

void DrawLines(){
    for (int i = 0; i <= map_h; i++)
    {
        DrawLine(30, i*TILE_SIZE + 30, TILE_SIZE*map_w + 30, i*TILE_SIZE + 30,map_line_color);
    }
    for (int i = 0; i <= map_w; i++)
    {
        DrawLine(i*TILE_SIZE + 30, 30, i*TILE_SIZE + 30, TILE_SIZE*map_w + 30,map_line_color);
    }
}

void DrawMap()
{
    for (int i = 0; i < map_h; i++)
    {
        for (int j = 0; j < map_w; j++)
        {
            if (world_map[i][j] == 1)
            {
                DrawRectangle(j * TILE_SIZE + 30, i * TILE_SIZE + 30, TILE_SIZE, TILE_SIZE, DARKGRAY);
            }
            else
            {
                DrawRectangle(j * TILE_SIZE + 30, i * TILE_SIZE + 30, TILE_SIZE, TILE_SIZE, LIGHTGRAY);
            }
        }
    }
    DrawLines();
    write_text_map("MAP VIWE - press M to return to camera", 10, 10, 20, GREEN);
}
