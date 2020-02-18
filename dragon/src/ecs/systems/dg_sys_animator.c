/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** system : animator
*/

#include <stdlib.h>
#include "libdragon.h"
#include "dg_system.h"

void dg_sys_animator(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    dg_entity_t *camera = dg_get_entity(*entities, "camera");
    sfVector2f *c_pos = (sfVector2f *)(dg_entity_get_component(camera, "pos"));
    dg_animator_t *animator = (dg_animator_t *)
        (dg_entity_get_component(entity, "animator"));
    sfVector2f *pos = (sfVector2f *)
        (dg_entity_get_component(entity, "pos"));
    sfSprite *sprite = 0;

    if (!dg_system_require(entity, 2, "animator", "pos") || !camera)
        return;
    sprite = sfSprite_create();
    sfSprite_setPosition(sprite, *pos);
    dg_animator_update_sprite(animator, sprite, dt.microseconds);
    dg_camera_render(*c_pos, sprite, w);
}
