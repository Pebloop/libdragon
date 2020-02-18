/*
** EPITECH PROJECT, 2019
** screensaver
** File description:
** manage the general use of the lib
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

dg_scene_t *scene_game(void)
{
    dg_scene_t *scene = dg_scene_create("game");

    dg_scene_add_ent(scene, entity_player_create());
    dg_scene_add_ent(scene, dg_ent_camera(0, 0));
    dg_scene_add_sys(scene, dg_system_create(&system_player_control, 0));
    dg_scene_add_sys(scene, dg_system_create(&dg_sys_animator, 1));
    scene->run = 1;
    scene->display = 1;
    return scene;
}
