// RENDERWINDOW SOURCE FILE

#include "renderwindow.h"

struct SDL_Object* initialize_SDL()
{
	const char* title = "Conway's Game of Life";

	SDL_Object* new_image;
	new_image = (struct SDL_Object*)malloc(sizeof(struct SDL_Object));
	if(new_image == NULL)
	{
		printf("Error... could not allocate SDL Object.\n");
		SDL_Quit();
		return NULL;
	}
	new_image -> window = define_window(new_image, title);
	new_image -> renderer = define_renderer(new_image);
	new_image -> grid = define_grid(1);
	return new_image;
}

SDL_Window* define_window(SDL_Object* image, const char* title)
{
	SDL_Window* new_window;
	new_window = SDL_CreateWindow(
		title, 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 
		WIDTH, 
		HEIGHT, 
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
	);
	if(new_window == NULL)
	{
		printf("Error... could not create window: %s\n", SDL_GetError());
		SDL_Quit();
		return NULL;
	}
	return new_window;
}

SDL_Renderer* define_renderer(SDL_Object* image) 
{
	SDL_Renderer* new_renderer;
	new_renderer = SDL_CreateRenderer(
		image -> window,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
	if(new_renderer == NULL)
	{
		printf("Error... could not create renderer: %s\n", SDL_GetError());
		return NULL;
	}
	return new_renderer;
}

SDL_Texture* define_texture(SDL_Object* image, char* filename)
{
	SDL_Texture* texture = NULL;
	return texture;
}

void cli_display()
{
	printf("Welcome to John Conway's Game of Life.\n");
	printf("Choose from the options below:\n");
	printf(">> 0) Create new simulation\n");
	printf(">> 1) Pause/unpause current simulation\n");
	printf(">> 2) Simulate with Moore neighborhood\n");
	printf(">> 3) Simulate with Von Neumann neighborhood\n");
	printf(">> 4) Design a custom neighborhood\n");
	printf(">> 5) Zoom in\n");
	printf(">> 6) Zoom out\n");
	return;
}

void click_update(SDL_Object* image, SDL_Event event)
{
	int col = event.motion.x / CELL_WIDTH;
	int row = event.motion.y / CELL_HEIGHT;
	toggle_cell(image -> grid, row, col);
}

void draw(SDL_Object* image)
{
	Grid grid = image -> grid;
	SDL_SetRenderDrawColor(image -> renderer, 0, 0, 0, 255);
	SDL_RenderClear(image -> renderer);

	for(int row = 0; row < DIM; row++)
	{
		for(int col = 0; col < DIM; col++)
		{
			if(grid[row][col].state == ALIVE)
			{
				SDL_SetRenderDrawColor(image -> renderer, 255, 255, 255, 255);
			}
			else
			{
				SDL_SetRenderDrawColor(image -> renderer, 0, 0, 0, 255);
			}
			SDL_Rect cell = {
				CELL_WIDTH * col,
				CELL_HEIGHT * row,
				CELL_WIDTH,
				CELL_HEIGHT
			};
			SDL_RenderFillRect(image -> renderer, &cell);
		}
	}
	SDL_RenderPresent(image -> renderer);
}

void cleanup_SDL(SDL_Object* image)
{
	SDL_DestroyWindow(image -> window);
	SDL_DestroyRenderer(image -> renderer);
	free(image);
}

