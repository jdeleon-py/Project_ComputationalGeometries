// CELLULAR AUTOMATA MAIN PROGRAM FILE
// - JAMES DELEON

#include "cell.h"
#include "grid.h"
#include "renderwindow.h"

void cli_handler(std::string& text)
{
	system("clear");
	// add a menu?
	std::cout << ">> ";
	text += event.text.text;
	std::cout << text << std::endl;
}

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
		while(SDL_PollEvent(&event) != 0)
		{
			switch(event.type)
			{
				case SDL_QUIT:
					running = false;
					break;

				case SDL_KEYDOWN:
					if(event.key.keysym.sym == SDLK_p) {paused = !paused;}
					if(event.key.keysym.sym == SDLK_x) {window.grid = Grid();}
					// handling text input
					if(event.key.keysym.sym == SDLK_BACKSPACE && text.length() > 0)
					{
						text = text.substr(0, text.length() - 1);
						cli_handler(text);
					}
					if(event.key.keysym.sym == SDLK_RETURN && text.length() > 0)
					{
						text = "";
						cli_handler(text);
					}
					break;
				
				case SDL_TEXTINPUT:
					cli_handler(text);
					break;

				// add features to zoom in/out?

				// able to click around when paused to change states
				case SDL_MOUSEBUTTONDOWN:
					// todo: current implementation does not update the window
					click_update(event);
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