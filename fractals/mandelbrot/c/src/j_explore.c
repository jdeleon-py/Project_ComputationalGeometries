// SDL2 JULIA SET RENDERER
// - JAMES DELEON

#include "mandelbrot.h"
#include "renderwindow.h"

#define X_MIN           -1.5
#define X_MAX            1.5
#define Y_MIN           -1.5
#define Y_MAX            1.5

void render_julia(Dimensions* map, SDL_Object* window, Complex seed);

/*
 *
*/

int main(int argc, char* argv[])
{
	return 0;
}

void render_julia(Dimensions* map, SDL_Object* window, Complex seed)
{
	// seed value corresponds to constant c of the power iteration (z^2 + c)
	for(int y = 0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
			Site* pix = build_site(x, y);
			pix -> iterations = julia(map, pix, seed);
			draw_site(window, pix);
			destroy_site(pix);
		}
		SDL_RenderPresent(window -> renderer);
	}
	printf("Render complete.\n");
}

/* END FILE */
