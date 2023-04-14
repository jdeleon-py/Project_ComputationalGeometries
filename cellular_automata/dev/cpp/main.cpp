// MAIN FILE

#include "cell.h"
#include "grid.h"
#include "renderwindow.h"

// implement framerate calculation function to compare against python's framerate

int main(int argc, char* args[])
{
	if(SDL_Init(SDL_INIT_VIDEO) > 0) {std::cout << "SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;}
	if(!(IMG_Init(IMG_INIT_PNG))) {std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;}

	RenderWindow window("John Conway's Game of Life", WIDTH, HEIGHT);
	SDL_Event event;
	bool paused = false;
	bool running = true;

	while(running == true)
	{
		// Draw and update environment
		window.draw();
		window.grid.eval_state();

		// Get our controls and events
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT) {running = false;}
			if(event.type == SDL_KEYDOWN)
			{
				// if event type is 'x' then restart
				// add features to zoom in/out?

				// space bar pauses/unpauses sim
				if(event.key.keysym.sym == SDLK_SPACE)
				{
					paused = !paused;
					while(paused)
					{
						SDL_Delay(100);
						if(event.key.keysym.sym == SDLK_SPACE) {paused = !paused;}
					} //work in progress
				}

				// able to click around when paused to change states
			}
		}
		// maintain a constant framerate
		SDL_Delay(50);
	}
	window.cleanup();
	SDL_Quit();
}

