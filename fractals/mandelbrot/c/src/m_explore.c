// SDL2 MANDELBROT SET RENDERER
// - JAMES DELEON

#include "mandelbrot.h"
#include "renderwindow.h"

#define X_MIN           -2.0
#define X_MAX            1.0
#define Y_MIN           -1.5
#define Y_MAX            1.5

void render_mandelbrot(Dimensions* map, SDL_Object* window, int offset);

/*
 *
*/

int main(int argc, char* argv[])
{
	return 0;
}

void render_mandelbrot(Dimensions* map, SDL_Object* window, int offset)
{
	//SDL_RenderClear(window -> renderer); //leave commented for visual effect
	for(int y = 0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
			Site* pix = build_site(x, y);
			pix -> iterations = mandelbrot(map, pix, offset);
			draw_site(window, pix);
			destroy_site(pix);
		}
		SDL_RenderPresent(window -> renderer);
	}
	printf("Render complete!\n");
}

/* END FILE */
