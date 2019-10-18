/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** define the framebuffer struct
*/

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

#include <SFML/Graphics.h>

typedef struct framebuffer
{
    sfUint8 *pixels;
    int width;
    int height;
    sfSprite *sp;
} framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int, unsigned int);

int framebuffer_destroy(framebuffer_t *);

void framebuffer_update(framebuffer_t *, sfRenderWindow *);

#endif
