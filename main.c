#include "libdragon.h"
unsigned int pos = 0;

int dg_init(framebuffer_t *back_fb)
{
	return 0;
}

int dg_loop(framebuffer_t *back_fb)
{
	sfVector2u vector = {pos, pos * 0.5};
    sfVector2u p1 = {100, 100};
    sfVector2u p2 = {pos, pos * 0.5};

	for (int x = 0; x < 1920; x++)
		for (int y = 0; y < 1024; y++)
			put_pixel_in_fb(back_fb, x, y, sfBlack);
		draw_square(back_fb, vector, pos * 0.1, sfBlue);
        set_thickness(back_fb, 10);
        draw_line(back_fb, p1, p2, sfGreen);
	pos+=5;
	return 0;
}

int main(void)
{
	dg_play(1920, 1024, "test");
    return 0;
}
