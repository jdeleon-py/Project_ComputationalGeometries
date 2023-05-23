// SDL2 RENDERER TEST FILE
// - JAMES DELEON

#include "renderwindow.h"
#include "mandelbrot.h"

#define X_MIN             -2
#define X_MAX              1
#define Y_MIN           -1.5
#define Y_MAX            1.5

// this file will display a window and ui functions
// ui functions:
// - click mouse to insert point

void render_mandelbrot(Dimensions* map, SDL_Object* window)
{
	SDL_RenderClear(window -> renderer);
	for(int y = 0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
			Site* pix = build_site(x, y);
			pix -> iterations = mandelbrot(map, pix); 
			draw_site(window, pix);
			destroy_site(pix);
		}
		SDL_RenderPresent(window -> renderer);
	}
	printf("Render complete!\n");
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
	render_mandelbrot(map_dim, window);

	dragging = false;
	running = true;
	while(running == true)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT) {running = false;}
			if(click_and_drag(event, map_dim, &dragging))
			{
				printf("New map generated!\n");
				print_map(map_dim);
				render_mandelbrot(map_dim, window);
			}
		}
		// update game state

		// draw to window
		SDL_RenderPresent(window -> renderer);
	}

	destroy_map(map_dim);
	cleanup_SDL(window);
	return 0;
}

