#include "libdragon.h"

unsigned int state = 0;
float force = 1;
const float MPI = 3.1415926535;
float pos = 0;
float test = 0;

int dg_init(framebuffer_t *back_fb)
{
	return 0;
}

int dg_loop(framebuffer_t *back_fb)
{
    float x = 910 + dg_cos(pos) * 400;
    float y = 512 + dg_sin(pos) * 200;
    sfVector2u hook = {910, 100};
    sfVector2u medal = {(int)(x), (int)(y)};
    sfVector2u circle = {910 + dg_cos(test) * 200, 512 + dg_sin(test) * 200};

	for (int x = 0; x < 1920; x++)
		for (int y = 0; y < 1024; y++)
			put_pixel_in_fb(back_fb, x, y, sfBlack);
    draw_circle(back_fb, circle, 20, sfRed);
    draw_line(back_fb, hook, medal, sfYellow);
    put_pixel_in_fb(back_fb, 910, 512, sfGreen);
    draw_circle(back_fb, medal, 50, sfWhite);
    if (pos >= MPI) {
        state = 1;
        force = 1;
    }
    if (pos <= 0) {
        state = 0;
        force = 1;
    }
    if (state == 0) {
        pos += 0.01 * force;
        if (x < 910)
            force -= 0.5;
        else
            force += 0.5;
    }
    if (state == 1) {
        pos -= 0.01 * force;
        if (x < 910)
            force += 0.5;
        else
            force -= 0.5;
    }
    test += 0.1;
	return 0;
}

int main(void)
{
	dg_play(1920, 1024, "test");
    return 0;
}
