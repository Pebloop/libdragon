/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** manage the general use of the lib
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "framebuffer.h"

void *dg_init(framebuffer_t *, sfRenderWindow *, int);

void dg_end(void *, int);

int dg_loop(framebuffer_t *, sfRenderWindow *, void *, sfTime, int);

static void dg_close_window(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
}

static void dg_render_screen(
    sfRenderWindow *window,
    void *var,
    framebuffer_t *fb,
    int id
    )
{
    sfEvent event;
    sfClock *clock = sfClock_create();
    sfTime dt = {0};

    while (sfRenderWindow_isOpen(window)) {
        dg_close_window(window, event);
        dg_loop(fb, window, var, dt, id);
        framebuffer_update(fb, window);
        sfRenderWindow_display(window);
        dt = sfClock_getElapsedTime(clock);
        sfClock_restart(clock);
    }
    dg_end(var, id);
    sfClock_destroy(clock);
}

void dg_play(unsigned int width, unsigned int height, char *name, int id)
{
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, name, sfClose, NULL);
    framebuffer_t *back_fb = framebuffer_create(mode.width, mode.height);
    void *var = 0;

    var = dg_init(back_fb, window, id);
    sfRenderWindow_clear(window, sfBlack);
    dg_render_screen(window, var, back_fb, id);
    framebuffer_destroy(back_fb);
    sfRenderWindow_destroy(window);
}
