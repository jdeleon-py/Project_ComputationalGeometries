// MAIN FILE

#include "cell.h"
#include "grid.h"
#include "renderwindow.h"

int main(int argc, char* args[])
{
	if(SDL_Init(SDL_INIT_VIDEO) > 0) {std::cout << "SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;}
	if(!(IMG_Init(IMG_INIT_PNG))) {std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;}

	RenderWindow window("John Conway's Game of Life", WIDTH, HEIGHT);
	SDL_Event event;
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
		}

		// maintain a constant framerate
		SDL_Delay(30);
	}

	window.cleanup();
	SDL_Quit();
}

