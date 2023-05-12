// SDL2 RENDERER TEST FILE
// - JAMES DELEON

#include "renderwindow.h"

// this file will display a window and ui functions
// ui functions:
// - click mouse to insert point

int main(int argc, char* argv[])
{
	/*
	* TODO: add functions to move around environment while zoomed in
	*/
	SDL_Object* window = NULL;
	bool running;
	SDL_Event event;

	window = initialize_SDL();

	running = true;
	while(running == true)
	{
		unsigned int x, y;
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT) {running = false;}
			if(event.type == SDL_MOUSEBUTTONDOWN)
			{
				x = event.button.x;
				y = event.button.y;
				printf("Mouse click at: (%d, %d)\n", x, y);
			}
		}

		// update game state
		SDL_SetRenderDrawColor(window -> renderer, 0, 0, 0, 255);
		SDL_RenderClear(window -> renderer);

		// draw to window
		SDL_RenderPresent(window -> renderer);
	}

	cleanup_SDL(window);
	return 0;
}
