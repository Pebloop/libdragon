/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** define the dg_scene_manager struct
*/

#ifndef DG_SCENE_MANAGER_H_
#define DG_SCENE_MANAGER_H_

#include "dg_scene.h"

typedef struct dg_scene_manager
{
    dg_scene_t **scenes;
} dg_scene_manager_t;

void dg_scene_manager_create(void);

void dg_scene_manager_add_scene(dg_scene_t *);

dg_scene_manager_t *dg_scene_manager(void);

void dg_scene_manager_destroy(void);

void dg_scene_manager_reload(char *, dg_scene_t *);

int dg_scene_manager_get_scene_id(char *);

dg_scene_t *dg_scene_manager_get_scene(char *);

int dg_scene_manager_scene_len(void);

void dg_scene_manager_update(dg_window_t *, sfTime);

#endif /*DG_SCENE_MANAGER_H_*/
