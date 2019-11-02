/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** include the drawing part
*/

#ifndef DG_DRAWING_H_
#define DG_DRAWING_H_

#include <SFML/Graphics.h>
#include "framebuffer.h"

int put_pixel_in_fb(framebuffer_t *, unsigned int, unsigned int, sfColor);

void draw_square(framebuffer_t *, sfVector2u, unsigned int, sfColor);

void draw_rectangle(framebuffer_t *, sfVector2u, sfVector2u, sfColor);

int draw_line(framebuffer_t *, sfVector2u, sfVector2u, sfColor);

void draw_circle(framebuffer_t *, sfVector2u, unsigned int, sfColor);

#endif
