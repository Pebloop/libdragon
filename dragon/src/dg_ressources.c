/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** dg_roussrces.c
*/

#include <stdlib.h>
#include "dg_ressources.h"

dg_ressources_t *dg_ressources(void)
{
    static dg_ressources_t ressources = {0};

    if (!ressources.sheets) {
        ressources.sheets = malloc(sizeof(dg_spritesheet_t *));
        ressources.sheets[0] = 0;
    }
    return &ressources;
}

void dg_ressources_add_spritesheet(char *path, int width, int height)
{
    dg_ressources_t *ressources = dg_ressources();
    dg_spritesheet_t **old = ressources->sheets;
    dg_spritesheet_t *sheet = dg_spritesheet_create(path, width, height);
    int size = 0;

    if (!sheet)
        return;
    for (size = 0; old[size]; size++);
    ressources->sheets = malloc(sizeof(dg_spritesheet_t *) * (size + 2));
    for (int i = 0; i < size; i++)
        ressources->sheets[i] = old[i];
    free(old);
    ressources->sheets[size] = sheet;
    ressources->sheets[size + 1] = 0;
}

dg_spritesheet_t *dg_ressources_get_spritesheet(int id)
{
    dg_ressources_t *ressources = dg_ressources();

    return ressources->sheets[id];
}

void dg_ressources_destroy(void)
{
    dg_ressources_t *ressources = dg_ressources();

    for (int i = 0; ressources->sheets[i]; i++) {
        dg_spritesheet_free(ressources->sheets[i]);
    }
    free(ressources->sheets);
}
