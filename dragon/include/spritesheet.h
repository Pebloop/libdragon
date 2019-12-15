/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** define the spritesheet struct
*/

#ifndef SPRITESHEET_H_
#define SPRITESHEET_H_

#include <SFML/Graphics.h>

typedef struct spritesheet
{
    sfTexture *sheet;
    unsigned int x;
    unsigned int y;
} spritesheet_t;

spritesheet_t *spritesheet_create(char *, int, int);

void spritesheet_free(spritesheet_t *);

void spritesheet_to_sprite(spritesheet_t *, sfSprite *, int);

#endif
