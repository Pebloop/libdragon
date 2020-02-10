/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** dg_scene
*/

#include <stdlib.h>
#include "dg_scene.h"
#include "epitech_tools.h"

void dg_scene_add_ent(dg_scene_t *scene, dg_entity_t *entity)
{
    if (!scene || !entity)
        return;
    dg_arr_add_begin(&(scene->entities), entity);
}

dg_entity_t *dg_get_entity(dg_array_t *entities, char *name)
{
    dg_entity_t *ent = 0;

    if (!entities || !name)
        return 0;
    while (entities && entities->data) {
        ent = ((dg_entity_t *)(entities->data));
        if (!dg_strcmp(ent->name, name))
            return ent;
        entities = entities->next;
    }
    return 0;
}
