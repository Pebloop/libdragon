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
    animator_t *animator;
    animation_t *down;
    animation_t *right;
    animation_t *up;
    animation_t *left;
    sfSprite *sprite;
    float i;
} val_t;

void *dg_init(framebuffer_t *back_fb, sfRenderWindow *window, int id)
{
    sfVector2f scale = {5, 5};
    val_t *v = malloc(sizeof(val_t));

    v->sprite = sfSprite_create();
    v->ss = spritesheet_create("res/bat.png", 32, 32);
    v->animator = animator_create();
    v->down = animation_create(v->ss, 0.00001);
    v->right = animation_create(v->ss, 0.00001);
    v->up = animation_create(v->ss, 0.00001);
    v->left = animation_create(v->ss, 0.00001);
    v->i = 0;
    animation_add(v->down, 0);
    animation_add(v->down, 1);
    animation_add(v->down, 2);
    animation_add(v->down, 3);

    animation_add(v->right, 4);
    animation_add(v->right, 5);
    animation_add(v->right, 6);
    animation_add(v->right, 7);

    animation_add(v->left, 12);
    animation_add(v->left, 13);
    animation_add(v->left, 14);
    animation_add(v->left, 15);

    animation_add(v->up, 8);
    animation_add(v->up, 9);
    animation_add(v->up, 10);
    animation_add(v->up, 11);

    animator_add(v->animator, "down", v->down);
    animator_add(v->animator, "right", v->right);
    animator_add(v->animator, "up", v->up);
    animator_add(v->animator, "left", v->left);

    sfSprite_setScale(v->sprite, scale);
    return v;
}

int dg_loop(framebuffer_t *back_fb, sfRenderWindow *window, void *var, sfTime dt, int id)
{
    val_t *v = ((val_t *)(var));
    sfVector2f move = {0, 0};

    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        move.x += 1;
        animator_set_animation(v->animator, "right");
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        move.x -= 1;
        animator_set_animation(v->animator, "left");
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        move.y += 1;
        animator_set_animation(v->animator, "down");
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        move.y -= 1;
        animator_set_animation(v->animator, "up");
    }
    sfSprite_move(v->sprite, move);
    sfRenderWindow_clear(window, sfBlack);
    animator_update_sprite(v->animator, v->sprite, ((int)(v->i)));
    sfRenderWindow_drawSprite(window, v->sprite, NULL);
    v->i += dt.microseconds * v->down->speed;
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
