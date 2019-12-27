/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** define the dg_entity struct
*/

#ifndef DG_ENTITY_H_
#define DG_ENTITY_H_

#include "dg_component.h"

typedef struct dg_entity
{
    dg_component_t **components;
    unsigned int quantity;
} dg_entity_t;

dg_entity_t *dg_entity_create();

void dg_entity_destroy(dg_entity_t *);

void dg_entity_add(dg_entity_t *, dg_component_t *);

int dg_entity_is_component(dg_entity_t *, char *);

void *dg_entity_get(dg_entity_t *, char *);

#endif /*DG_ENTITY_H*/
