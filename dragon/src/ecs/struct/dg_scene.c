/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** dg_scene
*/

#include <stdlib.h>
#include "dg_scene.h"
#include "epitech_tools.h"

dg_scene_t *dg_scene_create(void)
{
    dg_scene_t *scene = malloc(sizeof(dg_scene_t));

    if (!scene)
        return 0;
    scene->camera.x = 0;
    scene->camera.y = 0;
    scene->entities = 0;
    scene->ent_len = 0;
    scene->systems = 0;
    scene->sys_len = 0;
    return scene;
}

void dg_scene_add_ent(dg_scene_t *scene, dg_entity_t *entity)
{
    dg_entity_t **entities = 0;

    if (!scene || !entity)
        return;
    entities = malloc(sizeof(dg_entity_t *) * (scene->ent_len + 1));
    if (!entities)
        return;
    if (scene->ent_len > 0) {
        for (int i = 0; i < scene->ent_len; i++)
            entities[i] = scene->entities[i];
        free(scene->entities);
    }
    entities[scene->ent_len] = entity;
    scene->entities = entities;
    scene->ent_len++;
}

void dg_scene_add_sys(dg_scene_t *scene, dg_system_t *system)
{
    dg_system_t **systems = 0;

    if (!scene || !system)
        return;
    systems = malloc(sizeof(dg_system_t *) * (scene->sys_len + 1));
    if (!systems)
        return;
    if (scene->sys_len > 0) {
        for (int i = 0; i < scene->sys_len; i++)
            systems[i] = scene->systems[i];
        free(scene->systems);
    }
    systems[scene->sys_len] = system;
    scene->systems = systems;
    scene->sys_len++;
}

void dg_scene_destroy(dg_scene_t *scene)
{
    if (!scene)
        return;
    if (scene->entities) {
        for (int i = 0; i < scene->ent_len; i++)
            dg_entity_destroy(scene->entities[i]);
        free(scene->entities);
    }
    if (scene->systems) {
        for (int i = 0; i < scene->sys_len; i++)
            dg_system_destroy(scene->systems[i]);
        free(scene->systems);
    }
}

void dg_scene_update(dg_scene_t *scene, dg_window_t *w, sfTime dt)
{
    int sp_component = -1;
    sfSprite *sprite = 0;

    for (int y = 0; y < scene->ent_len; y++) {
        for (int i = 0; i < scene->sys_len; i++) {
            scene->systems[i]->system(scene->entities[y], w, dt);
        }
        sp_component = dg_entity_has_component(scene->entities[y], "sprite");
        if (sp_component >= 0) {
            sprite = (sfSprite *)(dg_entity_get_component(scene->entities[y],
                "sprite"));
            sfRenderWindow_drawSprite(w->window, sprite, NULL);
        }
    }
}
