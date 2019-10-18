/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** manage the general use of the lib
*/

#include <SFML/Graphics.h>
#include "framebuffer.h"

int dg_init(framebuffer_t *);

int dg_loop(framebuffer_t *);

int dg_play(unsigned int width, unsigned int height, char *name)
{
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, name,
                                                   sfResize | sfClose, NULL);
    framebuffer_t *back_fb = framebuffer_create(mode.width, mode.height);
    int (*init)(framebuffer_t *) = &dg_init;
    int (*loop)(framebuffer_t *) = &dg_loop;
    sfEvent event;

    (*init)(back_fb);
    sfRenderWindow_clear(window, sfBlack);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        (*loop)(back_fb);
        framebuffer_update(back_fb, window);
        sfRenderWindow_display(window);
    }
    framebuffer_destroy(back_fb);
    sfRenderWindow_destroy(window);
}
