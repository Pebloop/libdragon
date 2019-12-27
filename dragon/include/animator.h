/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** define the animator struct
*/

#ifndef ANIMATOR_H_
#define ANIMATOR_H_

#include <SFML/Graphics.h>
#include "dg_window.h"
#include "animation.h"

typedef struct animator
{
    animation_t **animations;
    char **keys;
    int length;
    int current;
    float time;
} animator_t;

animator_t *animator_create();

void animator_free(animator_t *);

void animator_add(animator_t *, char *name, animation_t *);

void animator_update_sprite(animator_t *, sfSprite *, int);

void animator_set_animation(animator_t *, char *);

#endif /*ANIMATOR_H*/
