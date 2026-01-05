#ifndef MAP_H
#define MAP_H
#include "raylib.h"

#define w_page 1200
#define h_page 800
#define map_w 20
#define map_h 20
#define TILE_SIZE 35
#define space 30

#define bg_1 CLITERAL(Color){180, 180, 180, 255}
#define map_line_color CLITERAL(Color){ 120, 120, 120, 255 }

extern int world_map[map_h][map_w];

void DrawMap();
void DrawLines();

#endif