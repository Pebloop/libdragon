/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** manage the framebuffer
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "framebuffer.h"

//intitialize the framebuffer
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height) {
    framebuffer_t *fb = malloc(sizeof(framebuffer_t));
    sfTexture *tex = sfTexture_create(width, height);
    sfSprite *sp = sfSprite_create();

    sfSprite_setTexture(sp, tex, sfFalse);
    fb->pixels = malloc(sizeof(sfUint8) * width * height * 4);
    fb->width = width;
    fb->height = height;
    fb->sp = sp;
    fb->thickness = 1;
    return fb;
}

//free the framebuffer
int framebuffer_destroy(framebuffer_t *fb)
{
    free(fb->pixels);
    sfTexture_destroy((sfTexture *) sfSprite_getTexture(fb->sp));
    sfSprite_destroy(fb->sp);
    free(fb);
    return 0;
}

//update the framebuffer
void framebuffer_update(framebuffer_t *fb, sfRenderWindow *window)
{
    sfTexture_updateFromPixels((sfTexture *) sfSprite_getTexture(fb->sp),
                               fb->pixels, fb->width, fb->height, 0, 0);    
    sfRenderWindow_drawSprite(window, fb->sp, NULL);
}

void set_thickness(framebuffer_t *fb, unsigned int thickness)
{
    fb->thickness = thickness;
}
