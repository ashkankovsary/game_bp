#ifndef RAYCASTER_H
#define RAYCASTER_H
#include "raylib.h"

#define sky_color CLITERAL(Color){135, 206, 235, 255}
#define wall_color_horizontal CLITERAL(Color){50, 50, 50, 255}
#define wall_color_vertical CLITERAL(Color){70, 70, 70, 255}
#define ground_color CLITERAL(Color){34, 139, 34, 255}

typedef struct intarray2
{
    int x;
    int y;
} intarray2;

void Raycasting(Player player1);

#endif