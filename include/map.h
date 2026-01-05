#ifndef MAP_H
#define MAP_H
#include "raylib.h"

#define w_page 1200
#define h_page 800
#define map_w 20
#define map_h 20
#define space 30.0f

// map value
#define TILE_SIZE 35
#define map_offset_w 30
#define map_offset_h 30

#define wall_color CLITERAL(Color){ 80, 80, 80, 255}
#define bg_map CLITERAL(Color){ 200, 200, 200, 255}
#define map_line_color CLITERAL(Color){ 120, 120, 120, 255}

// mini map value
#define mini_tile_size 7
#define mini_map_offset_w w_page * 0.85f
#define mini_map_offset_h h_page * 0.05f

#define mini_wall_color CLITERAL(Color){ 80, 80, 80, 180}
#define mini_bg_map CLITERAL(Color){ 200, 200, 200, 180}
#define mini_map_line_color CLITERAL(Color){ 120, 120, 120, 180}


extern int world_map[map_h][map_w];

void WriteTextMap();
void DrawMap(int tile_size, int offset_w, int offset_h, Color wallcolor, Color bg_color, Color line_color);
void DrawLines(int tile_size, int offset_w, int offset_h, Color line_color);

#endif