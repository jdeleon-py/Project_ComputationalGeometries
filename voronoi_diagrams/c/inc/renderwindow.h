// SDL2 RENDERER HEADER FILE
// - JAMES DELEON

#ifndef __RENDERWINDOW_H__
#define __RENDERWINDOW_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "site.h"
#include "quadtree.h"

#define DIM 1024 //window width and height will be DIM (multiple of 2^n) pixels (for now)

typedef struct SDL_Object
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
} SDL_Object;

// Note: functional descriptions are found in associated source files

SDL_Object* initialize_SDL();

SDL_Object* define_window(SDL_Object* image, const char* title);
SDL_Object* define_renderer(SDL_Object* image);
SDL_Object* define_texture(SDL_Object* image, char* filename);

//void draw_point(SDL_Object* image, Point* point);
//void draw_site(SDL_Object* image, Site* site, int offset);
void draw_line_V(SDL_Object* image, unsigned int cx, unsigned int cy, unsigned int r);
void draw_line_H(SDL_Object* image, unsigned int cx, unsigned int cy, unsigned int r);

void draw_voronoi(SDL_Object* image, QuadTree* qtree, Site* vor_sites[]);

void cleanup_SDL(SDL_Object* image);

#endif

/* END FILE */