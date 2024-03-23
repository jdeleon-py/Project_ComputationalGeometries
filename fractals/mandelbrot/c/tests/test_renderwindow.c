// SDL2 RENDERER TEST FILE
// - JAMES DELEON

#include "renderwindow.h"
#include "mandelbrot.h"

#define X_MIN           -1.5
#define X_MAX            1.5
#define Y_MIN           -1.5
#define Y_MAX            1.5

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

int main(int argc, char* argv[])
{
	/*
	* TODO: add functions to move around environment while zoomed in
	*/
	SDL_Object* window = NULL;
	Dimensions* map_dim = NULL;
	bool running, dragging;
	SDL_Event event;

	map_dim = build_map(X_MIN, X_MAX, Y_MIN, Y_MAX);
	window = initialize_SDL();
	SDL_SetRenderDrawColor(window -> renderer, 0, 0, 0, 255);
	print_map(map_dim);
	//render_mandelbrot(map_dim, window, 0);
	Complex seed = {0.37, 0.16};
	render_julia(map_dim, window, seed);

	int offset = 0;
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
				//render_mandelbrot(map_dim, window);
				render_julia(map_dim, window, seed);
			}
			else if(event.type == SDL_KEYDOWN)
			{
				if(event.key.keysym.sym == SDLK_RETURN)
				{
					offset += 500;
					printf("Rendering with %d escape iterations...\n", MAX_ITERATIONS + offset);
					render_mandelbrot(map_dim, window, offset);
				}
			}
		}
		// update game state

		// draw to window
		//SDL_RenderPresent(window -> renderer);
	}

	destroy_map(map_dim);
	cleanup_SDL(window);
	return 0;
}

