#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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

void WriteTextMap(const char *text1, const char *text2)
{
    DrawText(text1, w_page * 0.01, h_page * 0.01, 20, text_map_and_camera);
    DrawText(text2, w_page * 0.01, h_page * 0.95, 20, text_map_and_camera);
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
            else if (world_map[i][j] == FREE_SPACE)
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

void MouseHover()
{
    DrawRectangle(TileHoverX() * TILE_SIZE + map_offset_w, TileHoverY() * TILE_SIZE + map_offset_h, TILE_SIZE, TILE_SIZE, tile_hover);
}

bool NotPlayerAndBorder(Vector2 position)
{
    if (TileHoverX() > 0 && TileHoverX() < map_w - 1 && TileHoverY() > 0 && TileHoverY() < map_h - 1 && !(TileHoverX() == TilePlayerX(position.x) && TileHoverY() == TilePlayerY(position.y)))
        return true;
    return false;
}

void saveGame(const char *filename, int world_map[map_h][map_w], Player *player)
{
    FILE *f = fopen(filename, "wb");
    if (!f)
        return;

    SaveData data;
    data.version = SAVE_VERSION;
    data.player = *player;
    memcpy(data.map, world_map, sizeof(data.map));

    fwrite(&data, sizeof(SaveData), 1, f);
    fclose(f);
}

int loadGame(const char *filename, int world_map[map_h][map_w], Player *player)
{
    FILE *f = fopen(filename, "rb");
    if (!f)
        return 0;

    SaveData data;
    fread(&data, sizeof(SaveData), 1, f);
    fclose(f);

    if (data.version != SAVE_VERSION)
    {
        printf("Save file version mismatch!\n");
        return 0;
    }

    memcpy(world_map, data.map, sizeof(data.map));
    *player = data.player;

    return 1;
}