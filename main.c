/*
** EPITECH PROJECT, 2019
** screensaver
** File description:
** manage the general use of the lib
*/

#include <stdlib.h>
#include "libdragon.h"

typedef struct val {
    spritesheet_t *ss;
    animation_t *animation;
    float i;
} val_t;

void *dg_init(framebuffer_t *back_fb, sfRenderWindow *window, int id)
{
    val_t *v = malloc(sizeof(val_t));

    v->ss = spritesheet_create("res/bat.png", 32, 32);
    v->animation = animation_create(v->ss, 0.00001);
    v->i = 0;
    animation_add(v->animation, 0);
    animation_add(v->animation, 1);
    animation_add(v->animation, 2);
    return v;
}

int dg_loop(framebuffer_t *back_fb, sfRenderWindow *window, void *var, sfTime dt, int id)
{
    val_t *v = ((val_t *)(var));
    sfSprite *sprite = sfSprite_create();

    sfRenderWindow_clear(window, sfBlack);
    animation_update_sprite(v->animation, sprite, ((int)(v->i)));
    sfRenderWindow_drawSprite(window, sprite, NULL);
    v->i += dt.microseconds * v->animation->speed;
    return 0;
}

void dg_end(void *var, int id)
{

}

int main(int argc, char **argv)
{
    dg_play(1920, 1080, "LibDragon", 0);
    return 0;
}
