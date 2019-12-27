/*
** EPITECH PROJECT, 2019
** libdragon example
** File description:
** player entity and system
*/

#include <stdlib.h>
#include "libdragon.h"

static animator_t *set_player_animator()
{
    animator_t *animator = animator_create();
    spritesheet_t *ss = spritesheet_create("res/bat.png", 32, 32);
    animation_t *down = animation_create(ss, 10);
    animation_t *right = animation_create(ss, 10);
    animation_t *up = animation_create(ss, 10);
    animation_t *left = animation_create(ss, 10);

    animation_add(down, 0);
    animation_add(down, 1);
    animation_add(down, 2);
    animation_add(down, 3);

    animation_add(right, 4);
    animation_add(right, 5);
    animation_add(right, 6);
    animation_add(right, 7);

    animation_add(left, 12);
    animation_add(left, 13);
    animation_add(left, 14);
    animation_add(left, 15);

    animation_add(up, 8);
    animation_add(up, 9);
    animation_add(up, 10);
    animation_add(up, 11);

    animator_add(animator, "down", down);
    animator_add(animator, "right", right);
    animator_add(animator, "up", up);
    animator_add(animator, "left", left);

    return animator;
}

dg_entity_t *entity_player_create()
{
    sfVector2f scale = {5, 5};
    dg_entity_t *player = dg_entity_create();
    sfSprite *sprite = sfSprite_create();
    animator_t *animator = set_player_animator();
    dg_component_t *c_sprite = dg_component_create("sprite", sprite);
    dg_component_t *c_animator = dg_component_create("animator", animator);
    dg_component_t *c_player = dg_component_create("player", NULL);

    dg_entity_add(player, c_sprite);
    dg_entity_add(player, c_animator);
    dg_entity_add(player, c_player);
    sfSprite_setScale(sprite, scale);
    return player;
}

void system_player_control(dg_entity_t *entity, dg_window_t *w, sfTime dt)
{
    sfVector2f move = {0, 0};
    animator_t *animator = (animator_t *)(dg_entity_get(entity, "animator"));
    sfSprite *sprite = (sfSprite *)(dg_entity_get(entity, "sprite"));

    if (!dg_system_require(entity, 3, "animator", "sprite", "player"))
        return;
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        move.x += 1;
        animator_set_animation(animator, "right");
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        move.x -= 1;
        animator_set_animation(animator, "left");
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        move.y += 1;
        animator_set_animation(animator, "down");
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        move.y -= 1;
        animator_set_animation(animator, "up");
    }
    sfSprite_move(sprite, move);
}
