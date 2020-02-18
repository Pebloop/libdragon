/*
** EPITECH PROJECT, 2019
** screensaver
** File description:
** manage the general use of the lib
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

void *dg_init(dg_window_t *window, void *import)
{
    dg_ressources_add_spritesheet("res/bat.png", 32, 32);
    dg_scene_manager_create();
    dg_scene_manager_add_scene(scene_game());
    return 0;
}

int dg_loop(dg_window_t *w, void *var, sfTime dt)
{
    sfRenderWindow_clear(w->window, sfBlack);
    dg_scene_manager_update(w, dt);
    return 10;
}

void dg_end(void *var, int id)
{
    dg_scene_manager_destroy();
    dg_ressources_destroy();
}

int main(int argc, char **argv)
{
    return dg_play((sfVector2u){1920, 1080}, "LibDragon", 0, NULL);
}
