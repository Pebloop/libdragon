/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** define the dg_ressources struct
*/

#ifndef DG_RESSOURCES_H_
#define DG_RESSOURCES_H_

#include "dg_spritesheet.h"
#include <SFML/Graphics.h>

typedef struct dg_ressources
{
    dg_spritesheet_t **sheets;
} dg_ressources_t;

dg_ressources_t *dg_ressources(void);

void dg_ressources_add_spritesheet(char *, int, int);

dg_spritesheet_t *dg_ressources_get_spritesheet(int);

void dg_ressources_destroy(void);

#endif /*DG_RESSOURCES_H*/
