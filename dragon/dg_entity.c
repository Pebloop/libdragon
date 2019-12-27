/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** dg_entity
*/

#include <stdlib.h>
#include "dg_entity.h"
#include "epitech_tools.h"

dg_entity_t *dg_entity_create(void)
{
    dg_entity_t *entity = malloc(sizeof(dg_entity_t));

    if (!entity)
        return 0;
    entity->components = 0;
    entity->quantity = 0;
    return entity;
}

void dg_entity_destroy(dg_entity_t *entity)
{
    if (!entity)
        return;
    if (entity->components) {
        for (int i = 0; i < entity->quantity; i++)
            dg_component_destroy(entity->components[i]);
        free(entity->components);
    }
    free(entity);
}

void dg_entity_add(dg_entity_t *entity, dg_component_t *component)
{
    dg_component_t **components = 0;

    if (!entity)
        return;
    components = malloc(sizeof(dg_component_t *) * (entity->quantity + 1));
    if (!components)
        return;
    if (entity->quantity > 0) {
        for (int i = 0; i < entity->quantity; i++)
            components[i] = entity->components[i];
        free(entity->components);
    }
    components[entity->quantity] = component;
    entity->components = components;
    entity->quantity++;
}

int dg_entity_is_component(dg_entity_t *entity, char *name)
{
    if (!entity || !name)
        return 0;
    for (int i = 0; i < entity->quantity; i++) {
        if (!dg_strcmp(entity->components[i]->name, name))
            return i;
    }
    return -1;
}

void *dg_entity_get(dg_entity_t *entity, char *name)
{
    if (!entity || !name)
        return 0;
    for (int i = 0; i < entity->quantity; i++) {
        if (!dg_strcmp(entity->components[i]->name, name))
            return entity->components[i]->data;
    }
    return 0;
}
