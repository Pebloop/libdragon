/*
** EPITECH PROJECT, 2019
** draw a square
** File description:
** draw rectangles
*/

#include "dg_drawing.h"

void draw_square(framebuffer_t *fb, sfVector2u position,
                 unsigned int size, sfColor color)
{
    for (int i = position.x; i < position.x + size; i++)
        for (int j = position.y; j < position.y + size; j++)
            put_pixel_in_fb(fb, i, j, color);
}

//draw a rectangle
void draw_rectangle(framebuffer_t *fb, sfVector2u position,
                    sfVector2u size, sfColor color)
{
    for (int i = position.x; i < position.x + size.x; i++)
        for (int j = position.y; j < position.y + size.y; j++)
            put_pixel_in_fb(fb, i, j, color);
}

