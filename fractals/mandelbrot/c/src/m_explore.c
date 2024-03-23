// SDL2 MANDELBROT SET RENDERER
// - JAMES DELEON

#include "mandelbrot.h"
#include "renderwindow.h"

#define X_MIN           -2.0
#define X_MAX            1.0
#define Y_MIN           -1.5
#define Y_MAX            1.5

/*
 * USER FUNCTIONS
 * - click and drag to zoom into segment
 * - press 'return' key to enhance the image's resolution
*/

void render_mandelbrot(Dimensions* map, SDL_Object* window, int offset);

int main(int argc, char* argv[])
{
	SDL_Object* window = NULL;
	Dimensions* map_dim = NULL;
	bool running, dragging;
	int offset = 0;
	SDL_Event event;

	map_dim = build_map(X_MIN, X_MAX, Y_MIN, Y_MAX);
	window = initialize_SDL();
	SDL_SetRenderDrawColor(window -> renderer, 0, 0, 0, 255);
	print_map(map_dim);
	render_mandelbrot(map_dim, window, offset);

	dragging = false;
	running = true;
	while(running == true)
	{
		while(SDL_PollEvent(&event))
		{
			Pixel p_start, p_stop;
			Complex z_start, z_stop;

			if(event.type == SDL_QUIT) {running = false;}
			else if(click_and_drag(window, event, &p_start, &p_stop, &dragging))
			{
				SDL_RenderPresent(window -> renderer);

				z_start.real = scale_x(map_dim, p_start.x);
				z_start.imag = scale_y(map_dim, p_start.y);
				z_stop.real = scale_x(map_dim, p_stop.x);
				z_stop.imag = scale_y(map_dim, p_stop.y);

				map_dim -> x_min = z_start.real;
				map_dim -> x_max = z_stop.real;
				map_dim -> y_min = z_start.imag;
				map_dim -> y_max = z_stop.imag;

				printf("New map generated!\n");
				print_map(map_dim);
				render_mandelbrot(map_dim, window, offset);
			}
			else if(event.type == SDL_KEYDOWN)
			{
				if(event.key.keysym.sym == SDLK_RETURN)
				{
					offset += 500;
					printf("Increasing resolution with %d escape iterations...\n", MAX_ITERATIONS + offset);
					render_mandelbrot(map_dim, window, offset);
				}
			}
		}
	}
	destroy_map(map_dim);
	cleanup_SDL(window);
	return 0;
}

void render_mandelbrot(Dimensions* map, SDL_Object* window, int offset)
{
	for(int y = 0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
			Site* pix = build_site(x, y);
			pix -> iterations = mandelbrot(map, pix, offset);
			draw_site(window, pix, offset);
			destroy_site(pix);
		}
		SDL_RenderPresent(window -> renderer);
	}
	printf("Render complete!\n");
}

/* END FILE */
