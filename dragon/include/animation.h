/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** define the spritesheet struct
*/

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <SFML/Graphics.h>
#include "spritesheet.h"

typedef struct animation
{
    spritesheet_t *sheet;
    int *frames;
    int size;
    float speed;
} animation_t;

animation_t *animation_create(spritesheet_t *, float);

void animation_free(animation_t *);

void animation_add(animation_t *, int);

void animation_update_sprite(animation_t *, sfSprite *, int);

#endif /*ANIMATION_H*/
