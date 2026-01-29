#ifndef MAP_H
#define MAP_H
#include "raylib.h"
#include "player.h"

#define w_page 1200
#define h_page 800
#define map_w 20
#define map_h 20
#define SAVE_VERSION 1

#define text_map_and_camera CLITERAL(Color){ 50, 200, 50, 255}

// map value
#define TILE_SIZE 35
#define map_offset_w 30
#define map_offset_h 30

#define wall_color CLITERAL(Color){ 80, 80, 80, 255}
#define bg_map CLITERAL(Color){ 200, 200, 200, 255}
#define map_line_color CLITERAL(Color){ 120, 120, 120, 255}
#define tile_hover CLITERAL(Color){ 150, 150, 150, 100}

// mini map value
#define mini_tile_size 7
#define mini_map_offset_w w_page * 0.99f - mini_tile_size * map_w
#define mini_map_offset_h h_page * 0.02f 

#define mini_wall_color CLITERAL(Color){ 80, 80, 80, 180}
#define mini_bg_map CLITERAL(Color){ 200, 200, 200, 180}
#define mini_map_line_color CLITERAL(Color){ 120, 120, 120, 180}

typedef struct {
    int version;
    int map[map_h][map_w];
    Player player;
} SaveData;

typedef enum {
    FREE_SPACE = 0,
    ROCKY_WALL = 1,
}BlockType;

extern int world_map[map_h][map_w];

void WriteTextMap(const char *text1,const char *text2);
void DrawMap(int tile_size, int offset_w, int offset_h, Color wallcolor, Color bg_color, Color line_color);
void DrawLines(int tile_size, int offset_w, int offset_h, Color line_color);
int TileHoverY();
int TileHoverX();
bool MouseInMap();
void MouseHover();
bool NotPlayerAndBorder(Vector2 position);
void saveGame(const char *filename, int map[map_h][map_w], Player *player);
int loadGame(const char *filename, int map[map_h][map_w], Player *player);

#endif