/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** dg_scene_manager
*/

#include <stdlib.h>
#include "dg_scene_manager.h"
#include "dg_scene.h"
#include "epitech_tools.h"

dg_scene_manager_t *dg_scene_manager(void)
{
    static dg_scene_manager_t *sm = 0;

    if (!sm)
        sm = malloc(sizeof(dg_scene_manager_t));
    return sm;
}

void dg_scene_manager_destroy(void)
{
    dg_scene_manager_t *sm = dg_scene_manager();

    if (sm->scenes) {
        for (int i = 0; sm->scenes[i]; i++)
            dg_scene_destroy(sm->scenes[i]);
        free(sm->scenes);
    }
    free(sm);
}

void dg_scene_manager_create(void)
{
    dg_scene_manager_t *sm = dg_scene_manager();

    if (!sm)
        return;
    sm->scenes = malloc(sizeof(dg_scene_t *));
    sm->scenes[0] = 0;
}

void dg_scene_manager_add_scene(dg_scene_t *scene)
{
    dg_scene_t **old_scenes = 0;
    dg_scene_manager_t *sm = dg_scene_manager();
    int nb_scenes = 0;

    if (!sm || !scene)
        return;
    if (sm->scenes) {
        for (nb_scenes = 0; sm->scenes[nb_scenes]; nb_scenes++);
        old_scenes = sm->scenes;
        sm->scenes = malloc(sizeof(dg_scene_t *) * (nb_scenes + 2));
        for (int i = 0; i < nb_scenes; i++)
            sm->scenes[i] = old_scenes[i];
        free(old_scenes);
    } else {
        sm->scenes = malloc(sizeof(dg_scene_t *) * 2);
    }
    sm->scenes[nb_scenes] = scene;
    sm->scenes[nb_scenes + 1] = 0;
}

int dg_scene_manager_get_scene_id(char *name)
{
    dg_scene_manager_t *sm = dg_scene_manager();
    int id = -1;

    for (int i = 0; sm->scenes[i]; i++)
         if (!dg_strcmp(name, sm->scenes[i]->name))
            id = i;
    return id;
}
