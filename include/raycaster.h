#ifndef RAYCASTER_H
#define RAYCASTER_H
#include "raylib.h"

#define sky_color CLITERAL(Color){135, 206, 235, 255}
#define ground_color CLITERAL(Color){34, 139, 34, 255}

typedef struct intarray2
{
    int x;
    int y;
} intarray2;

void Raycasting(Player player);

#endif