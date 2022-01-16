#include <stdlib.h>
#include "shape.h"

shape *shape_create(int id, int x, int y, type type, int r, int angle, int spin, float R, float G, float B, float A, int ttl)
{
    shape *newshape = (shape*)malloc(sizeof(*newshape));
    newshape->id = id;
    newshape->x = x;
    newshape->y = y;
    newshape->type = type;
    newshape->r = r;
    newshape->angle = angle;
    newshape->spin = spin;
    newshape->R = R;
    newshape->G = G;
    newshape->B = B;
    newshape->A = A;
    newshape->ttl = ttl;
    newshape->active = true;

    return newshape;
}

void shape_alpha(shape *shp, float A)
{
    shp->A = A;
}

void shape_r(shape *shp, int r)
{
    shp->r = r;
}

void shape_angle(shape *shp, int angle)
{
    angle %= 360;
    shp->angle = angle < 0 ? angle + 360 : angle;
}

void shape_rotate(shape *shp)
{
    shape_angle(shp, shp->angle + shp->spin);
}

void shape_fade_out(shape *shp, int r_step, float A_step)
{
    shape_r(shp, shp->r - r_step);
    shape_alpha(shp, shp->A - A_step);
    if (shp->type != circle)
    {
        shape_rotate(shp);
    }
}

void shape_deactivate(shape *shp)
{
    shp->active = false;
}

int shape_decrement_ttl(shape *shp)
{
    shp->ttl -= 1;
    return shp->ttl;
}

bool shape_is_visible(shape *shp)
{
    return shp->r > 0 && shp->A > 0.0f;
}

bool shape_is_active(shape *shp)
{
    return shp->active;
}