// SDL2 MOUSE CLICK TEST

#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>

int main(int argc, char* argv[])
{
	SDL_Window* window = SDL_CreateWindow("SDL2 Mouse Click Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_Event event;
	bool running = true;

	while(running == true)
	{
		while(SDL_PollEvent(&event) != 0)
		{
			if(event.type == SDL_QUIT) {running = false;}
		}

		if(event.type == SDL_MOUSEBUTTONDOWN)
		{
			int x = event.button.x;
			int y = event.button.y;

			// handle left mouse button click
			if(event.button.button == SDL_BUTTON_LEFT)
			{
				std::cout << "Left Button!" << std::endl;
				std::cout << "Coordinates: (" << x << ", " << y << ")" << std::endl;
			}

			// handle right mouse button click
			if(event.button.button == SDL_BUTTON_RIGHT)
			{
				std::cout << "Right Button!" << std::endl;
                                std::cout << "Coordinates: (" << x << ", " << y << ")" << std::endl;
			}
			std::cout << std::endl;
		}
		for(int i = 0; i < 10000000; i++);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
