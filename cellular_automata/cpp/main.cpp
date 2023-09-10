// CELLULAR AUTOMATA MAIN PROGRAM FILE
// - JAMES DELEON

#include "cell.h"
#include "grid.h"
#include "renderwindow.h"

int main(int argc, char* args[])
{
	if(SDL_Init(SDL_INIT_VIDEO) > 0) {std::cout << "SDL_Init has failed. SDL_Error: " << SDL_GetError() << std::endl;}
	if(!(IMG_Init(IMG_INIT_PNG))) {std::cout << "IMG_init has failed. SDL_Error: " << SDL_GetError() << std::endl;}

	RenderWindow window("John Conway's Game of Life", WIDTH, HEIGHT);
	SDL_Event event;
	bool paused = false;
	bool running = true;
	std::string text = "";

	SDL_StartTextInput();
	window.cli_handler(event, text);
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
		//TODO: how can i get rid of error chars on cli at start?
		while(SDL_PollEvent(&event) != 0)
		{
			switch(event.type)
			{
				case SDL_QUIT:
					running = false;
					break;

				case SDL_KEYDOWN:
					//TODO: if a functional key is a char, how can that letter not show up as text on the cli?
					if(event.key.keysym.sym == SDLK_1) {paused = !paused;}
					if(event.key.keysym.sym == SDLK_0) {window.grid = Grid();}
					if(event.key.keysym.sym == SDLK_BACKSPACE && text.length() > 0)
					{
						text = text.substr(0, text.length() - 1);
						window.cli_handler(event, text);
					}
					if(event.key.keysym.sym == SDLK_RETURN && text.length() > 0)
					{
						text = "";
						window.cli_handler(event, text);
					}
					break;
				
				case SDL_TEXTINPUT:
					window.cli_handler(event, text);
					break;

				// add features to zoom in/out?

				// able to click around when paused to toggle states
				case SDL_MOUSEBUTTONDOWN:
					window.click_update(event);
					break;

				default: break;
			}
		}
		SDL_Delay(32); // maintain constant framerate (~30 fps)
	}
	SDL_StopTextInput();
	window.cleanup();
	SDL_Quit();
}

/* END FILE */
