/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** Draw basics forms on a framebuffer
*/

#include <SFML/Graphics.h>
#include "framebuffer.h"

//change a pixel of a framebuffer
int put_pixel_in_fb(framebuffer_t *fb, unsigned int x,
                    unsigned int y, sfColor color)
{
    if (x >= fb->width || y >= fb->height)
        return 1;
    int pos = (x + y * fb->width) * 4;
    fb->pixels[pos] = color.r;
    fb->pixels[pos + 1] = color.g;
    fb->pixels[pos + 2] = color.b;
    fb->pixels[pos + 3] = color.a;
    return 0;
}
