// SDL2 RENDERER TEST FILE
// - JAMES DELEON

#include "renderwindow.h"
#include "mandelbrot.h"

// this file will display a window and ui functions
// ui functions:
// - click mouse to insert point

void render_mandelbrot(SDL_Object* window)
{
	for(int y = 0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
			Site* pix = build_site(x, y);
			pix -> iterations = mandelbrot(pix); 
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
	bool running;
	SDL_Event event;

	window = initialize_SDL();
	SDL_SetRenderDrawColor(window -> renderer, 0, 0, 0, 255);
	SDL_RenderClear(window -> renderer);
	render_mandelbrot(window);

	running = true;
	while(running == true)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT) {running = false;}
		}
		// update game state

		// draw to window
		SDL_RenderPresent(window -> renderer);
	}

	cleanup_SDL(window);
	return 0;
}
