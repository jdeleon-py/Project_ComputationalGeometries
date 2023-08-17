// SDL2 RENDERER HEADER FILE
// - JAMES DELEON

#ifndef __RENDERWINDOW_H__
#define __RENDERWINDOW_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "point.h"
#include "quadtree.h"

#define DIM 512 //window width and height will be DIM pixels (for now)

typedef struct SDL_Object
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
} SDL_Object;

SDL_Object* initialize_SDL();

SDL_Object* define_window(SDL_Object* image, const char* title);
SDL_Object* define_renderer(SDL_Object* image);
SDL_Object* define_texture(SDL_Object* image, char* filename);

void draw_point(SDL_Object* image, Point* point);
void draw_line_V(SDL_Object* image, unsigned int cx, unsigned int cy, unsigned int r);
void draw_line_H(SDL_Object* image, unsigned int cx, unsigned int cy, unsigned int r);
void draw_qtree();

void cleanup_SDL(SDL_Object* image);

#endif
