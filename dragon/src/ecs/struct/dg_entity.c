/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** dg_entity
*/

#include <stdlib.h>
#include "dg_entity.h"
#include "epitech_tools.h"

dg_entity_t *dg_entity_create(char *name)
{
    dg_entity_t *entity = malloc(sizeof(dg_entity_t));

    if (!entity)
        return 0;
    entity->name = name;
    entity->components = 0;
    return entity;
}

void dg_entity_destroy(dg_entity_t *entity)
{
    dg_array_t *tmp = 0;

    if (!entity)
        return;
    tmp = entity->components;
    while (tmp) {
        dg_component_destroy(tmp->data);
        tmp = tmp->next;
    }
    dg_arr_free_all(&(entity->components));
    free(entity);
}

void dg_entity_add_component(dg_entity_t *entity, dg_component_t *component)
{
    if (!entity || !component)
        return;
    dg_arr_add_begin(&(entity->components), component);
}

dg_component_t *dg_entity_rm_component(dg_entity_t *entity, char *name)
{
    int comp = -1;

    if (!entity || name)
        return 0;
    comp = dg_entity_has_component(entity, name);
    if (comp == -1)
        return 0;
    return dg_arr_remove_at(&(entity->components), comp);
}

void dg_entity_free_component(dg_entity_t *entity, char *name)
{
    int comp = -1;
    dg_component_t *component = 0;

    if (!entity || !name)
        return;
    comp = dg_entity_has_component(entity, name);
    if (comp == -1)
        return;
    component = dg_arr_remove_at(&(entity->components), comp);
    dg_component_destroy(component);
}
