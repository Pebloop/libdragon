/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** draw a circle
*/

#include "framebuffer.h"
#include "dg_drawing.h"

static int square(int nb)
{
    return nb * nb;
}

void display_circle(framebuffer_t *fb, int *coord, sfColor color)
{
    int x = coord[0] - coord[4];
    int y = coord[1] - coord[4];

    if (square(x) + square(y) <= square(coord[4]))
        put_pixel_in_fb(fb, x + coord[2], y + coord[3], color);
}

void draw_circle(framebuffer_t *fb, sfVector2u pos, unsigned int radius,
                 sfColor color)
{
    int coord[5] = {0, 0, pos.x, pos.y, radius};

    for (int x = 0; x < radius * 2; x++)
        for (int y = 0; y < radius * 2; y++) {
            coord[0] = x;
            coord[1] = y;
            display_circle(fb, coord, color);
        }
}
