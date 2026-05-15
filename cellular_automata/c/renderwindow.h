// RENDERWINDOW HEADER FILE

#ifndef __RENDERWINDOW_H__
#define __RENDERWINDOW_H__

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "grid.h"

#define WIDTH  		512
#define HEIGHT 		512

#define CELL_WIDTH  (int)(WIDTH / DIM)
#define CELL_HEIGHT (int)(HEIGHT / DIM)

typedef struct SDL_Object
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;

	Grid grid;
} SDL_Object;

struct SDL_Object* initialize_SDL();
SDL_Window* define_window(SDL_Object* image, const char* title);
SDL_Renderer* define_renderer(SDL_Object* image);
SDL_Texture* define_texture(SDL_Object* image, char* filename);

void cli_display();
void draw(SDL_Object* image);
void click_update(SDL_Object* image, SDL_Event event);
void cleanup_SDL(SDL_Object* image);

#endif
