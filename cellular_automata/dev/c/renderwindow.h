// RENDERWINDOW HEADER FILE

#ifndef __RENDERWINDOW_H__
#define __RENDERWINDOW_H__

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "grid.h"

#define WIDTH  		512
#define HEIGHT 		512

#define CELL_WIDTH  (int)(WIDTH / DIM)
#define CELL_HEIGHT (int)(HEIGHT / DIM)

struct SDL_Image
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
};

SDL_Window* define_window();
SDL_Renderer* define_renderer();
SDL_Texture* define_texture();

void draw();
void cleanup();

#endif
