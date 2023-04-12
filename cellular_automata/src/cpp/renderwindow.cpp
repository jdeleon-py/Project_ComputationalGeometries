// RENDERWINDOW SOURCE FILE

#include "renderwindow.h"

RenderWindow::RenderWindow(const char* title, int width, int height)
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if(window == NULL)
	{
		std::cout << "Window failed to initialize! Error: " << SDL_GetError() << std::endl;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	grid = Grid();
}

SDL_Texture* RenderWindow::LoadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if(texture == NULL) {std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;}
	return texture;
}

void RenderWindow::draw()
{
	for(int row = 0; row < (DIM - 1); row++)
	{
		for(int col = 0; col < (DIM - 1); col++)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			if((row == 0) || (row == DIM -1) || (col == 0) || (col == DIM - 1))
			{
				//set grid[row][col] state to zero along borders
				grid.get_cell(row, col).set_state(0);
			}
			if(grid.get_cell(row, col).get_state() == 1)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			}
			SDL_Rect cell = {CELL_WIDTH * col, CELL_HEIGHT * row, CELL_WIDTH, CELL_HEIGHT};
			SDL_RenderFillRect(renderer, &cell);
		}
	}
	SDL_RenderPresent(renderer);
}

void RenderWindow::cleanup()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
