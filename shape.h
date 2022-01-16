#ifndef SHAPE_H
#define SHAPE_H

#include <stdbool.h>

typedef enum type
{
    triangle = 0,
    square = 1,
    pentagon = 2,
    circle = 3,
    star = 4,
    star2 = 5,
    plus = 6
} type;

typedef struct shape
{
    int id;
    type type;
    int r;
    int angle, spin;
    int x, y;
    float R, G, B, A;
    int ttl;
    bool active;
} shape;

shape *shape_create(int id, int x, int y, type type, int r, int angle, int spin, float R, float G, float B, float A, int ttl);
void shape_rotate(shape *shp);
void shape_fade_out(shape *shp, int r_step, float A_step);
void shape_deactivate(shape *shp);
int shape_decrement_ttl(shape *shp);
bool shape_is_visible(shape *shp);
bool shape_is_active(shape *shp);

#endif