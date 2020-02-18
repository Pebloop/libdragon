/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** dg_scene
*/

#include <stdlib.h>
#include "dg_scene.h"
#include "epitech_tools.h"

dg_scene_t *dg_scene_create(char *name)
{
    dg_scene_t *scene = malloc(sizeof(dg_scene_t));

    if (!scene)
        return 0;
    scene->name = name;
    scene->entities = 0;
    scene->systems = 0;
    scene->run = 0;
    scene->display = 0;
    return scene;
}

void dg_scene_destroy(dg_scene_t *scene)
{
    dg_array_t *tmp = 0;

    if (!scene)
        return;
    tmp = scene->entities;
    while (tmp) {
        dg_entity_destroy(tmp->data);
        tmp = tmp->next;
    }
    dg_arr_free_all(&(scene->entities));
    tmp = scene->systems;
    while (tmp) {
        dg_system_destroy(tmp->data);
        tmp = tmp->next;
    }
    dg_arr_free_all(&(scene->systems));
    free(scene);
}

static void dg_scene_launch_system(dg_scene_t *scene, dg_system_t *sys,
    dg_window_t *w, sfTime dt)
{
    dg_array_t *tmp = 0;

    if (!scene->run)
        dt.microseconds = 0;
    for (tmp = scene->entities; tmp; tmp = tmp->next) {
        if (scene->run && !sys->is_render)
            sys->system(tmp->data, w, &(scene->entities),dt);
        else if (scene->display && sys->is_render)
            sys->system(tmp->data, w, &(scene->entities),dt);
    }
}

void dg_scene_update(dg_scene_t *scene, dg_window_t *w, sfTime dt)
{
    dg_array_t *sys = 0;
    int sp_component = -1;
    sfSprite *sprite = 0;

    if (!scene)
        return;
    for (sys = scene->systems; sys; sys = sys->next) {
        dg_scene_launch_system(scene, ((dg_system_t *)(sys->data)), w, dt);
    }
}
