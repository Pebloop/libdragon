/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** define the dg_scene struct
*/

#ifndef DG_SCENE_H_
#define DG_SCENE_H_

#include "dg_system.h"
#include "dg_entity.h"
#include "dg_window.h"
#include <SFML/Graphics.h>

typedef struct dg_scene
{
    sfVector2f camera;
    dg_entity_t **entities;
    unsigned int ent_len;
    dg_system_t **systems;
    unsigned int sys_len;
} dg_scene_t;

dg_scene_t *dg_scene_create();

void dg_scene_add_ent(dg_scene_t *, dg_entity_t *);

void dg_scene_add_sys(dg_scene_t *, dg_system_t *);

void dg_scene_destroy(dg_scene_t *);

void dg_scene_update(dg_scene_t *, dg_window_t *, sfTime);

#endif /*DG_SCENE_H*/
