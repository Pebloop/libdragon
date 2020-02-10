/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** dg_entity
*/

#include <stdlib.h>
#include "dg_entity.h"
#include "epitech_tools.h"

int dg_entity_has_component(dg_entity_t *entity, char *name)
{
    dg_array_t *tmp = 0;
    int index = -1;

    if (!entity || !name)
        return -1;
    tmp = entity->components;
    while (tmp) {
        index++;
        if (!dg_strcmp(((dg_component_t *)(tmp->data))->name, name))
            return index;
        tmp = tmp->next;
    }
    return -1;
}

void *dg_entity_get_component(dg_entity_t *entity, char *name)
{
    dg_array_t *tmp = 0;
    dg_component_t *component = 0;

    if (!entity || !name)
        return 0;
    tmp = entity->components;
    while (tmp && tmp->data) {
        component = ((dg_component_t *)(tmp->data));
        if (!dg_strcmp(component->name, name))
            return (component->data);
        tmp = tmp->next;
    }
    return 0;
}
