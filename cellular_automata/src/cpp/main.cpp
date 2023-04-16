// MAIN FILE

#include "cell.h"
#include "grid.h"
#include "renderwindow.h"

// implement framerate calculation function to compare against python's framerate

int main(int argc, char* args[])
{
	if(SDL_Init(SDL_INIT_VIDEO) > 0) {std::cout << "SDL_Init has failed. SDL_Error: " << SDL_GetError() << std::endl;}
	if(!(IMG_Init(IMG_INIT_PNG))) {std::cout << "IMG_init has failed. SDL_Error: " << SDL_GetError() << std::endl;}

	RenderWindow window("John Conway's Game of Life", WIDTH, HEIGHT);
	SDL_Event event;
	bool paused = false;
	bool running = true;

	while(running == true)
	{
		// Draw and update environment
		// (sim runs only when unpaused)
		if(paused == false)
		{
			window.draw();
			window.grid.eval_state();
		}

		// Get our controls and events
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					running = false;
					break;

				case SDL_KEYDOWN:
					if(event.key.keysym.sym == SDLK_SPACE) {paused = !paused;}
					if(event.key.keysym.sym == SDLK_x) {window.grid = Grid();}
					break;

				// add features to zoom in/out?

				// able to click around when paused to change states
				case SDL_MOUSEBUTTONDOWN:
					// todo: current implementation does not update the window
					if(paused == true) {window.click_update(event);}
					break;
			}
		}
		SDL_Delay(32); // maintain constant framerate (~30 fps)
	}
	window.cleanup();
	SDL_Quit();
}

