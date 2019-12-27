/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** system : animator
*/

#include <stdlib.h>
#include "libdragon.h"

void system_player_animator(dg_entity_t *entity, dg_window_t *w, sfTime dt)
{
    animator_t *animator = (animator_t *)(dg_entity_get(entity, "animator"));
    sfSprite *sprite = (sfSprite *)(dg_entity_get(entity, "sprite"));

    if (!dg_system_require(entity, 2, "animator", "sprite"))
        return;
    animator_update_sprite(animator, sprite, dt.microseconds);
}
