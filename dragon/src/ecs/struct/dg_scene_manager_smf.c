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

void dg_scene_manager_update(dg_window_t *w, sfTime dt)
{
    dg_scene_manager_t *sm = dg_scene_manager();

    for (int i = 0; sm->scenes[i]; i++) {
        if (sm->scenes[i]->run || sm->scenes[i]->display)
            dg_scene_update(sm->scenes[i], w, dt);
    }
}

dg_scene_t *dg_scene_manager_get_scene(char *name)
{
    dg_scene_manager_t *sm = dg_scene_manager();
    int id = -1;

    for (int i = 0; sm->scenes[i]; i++)
         if (!dg_strcmp(name, sm->scenes[i]->name))
            id = i;
    if (id == -1)
        return 0;
    return sm->scenes[id];
}

void dg_scene_manager_reload(char *name, dg_scene_t *scene)
{
    dg_scene_manager_t *sm = dg_scene_manager();
    int id = dg_scene_manager_get_scene_id(name);

    dg_scene_destroy(sm->scenes[id]);
    sm->scenes[id] = scene;
}

int dg_scene_manager_scene_len(void)
{
    dg_scene_manager_t *sm = dg_scene_manager();
    int size = 0;

    for (size = 0; sm->scenes[size]; size++);
    return size;
}

void dg_scene_manager_remove(char *name)
{
    dg_scene_manager_t *sm = dg_scene_manager();
    int len = dg_scene_manager_scene_len();
    dg_scene_t **old = sm->scenes;
    int id = dg_scene_manager_get_scene_id(name);

    if (id == -1)
        return;
    sm->scenes = malloc(sizeof(dg_scene_t *) * (len));
    for (int i = 0; i < id; i++)
        sm->scenes[i] = old[i];
    for (int i = id + 1; i < len; i++)
        sm->scenes[i - 2] = old[i];
    sm->scenes[len - 1] = 0;
}
