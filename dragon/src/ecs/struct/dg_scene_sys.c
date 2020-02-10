/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** dg_scene
*/

#include <stdlib.h>
#include "dg_scene.h"
#include "epitech_tools.h"

void dg_scene_add_sys(dg_scene_t *scene, dg_system_t *system)
{
    if (!scene || !system)
        return;
    dg_arr_add_begin(&(scene->systems), system);
}
