/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** include the whole lib
*/

#ifndef LIBDRAGON_H_
#define LIBDRAGON_H_

#include <SFML/Graphics.h>
#include "framebuffer.h"
#include "dg_window.h"
#include "dg_drawing.h"
#include "dg_math.h"
#include "spritesheet.h"
#include "animation.h"
#include "animator.h"
#include "dg_component.h"
#include "dg_entity.h"
#include "dg_system.h"
#include "dg_scene.h"

int dg_play(unsigned int, unsigned int, char *, int);

#endif
