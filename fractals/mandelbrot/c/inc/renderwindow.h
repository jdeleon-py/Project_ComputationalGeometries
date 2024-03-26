// SDL2 RENDERER HEADER FILE
// - JAMES DELEON

#ifndef __RENDERWINDOW_H__
#define __RENDERWINDOW_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "mandelbrot.h"
#include "color.h"

//#define DIM 512 //window width and height will be DIM (multiple of 2^n) pixels (for now)

typedef struct SDL_Object
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
} SDL_Object;

SDL_Object* initialize_SDL();
void cleanup_SDL(SDL_Object* image);

SDL_Object* define_window(SDL_Object* image, const char* title);
SDL_Object* define_renderer(SDL_Object* image);
SDL_Object* define_texture(SDL_Object* image, char* filename);

void draw_site(SDL_Object* image, Site* site, int offset);

// MJ_RENDER UTILITIES
void mj_click_point(SDL_Object* image, SDL_Event event, Pixel* pix);

// EXPLORE EXE UTILITIES
void draw_zoom_window(SDL_Object* image, SDL_Event event, Pixel* p_start, Pixel* p_stop);
bool click_and_drag(SDL_Object* image, SDL_Event event, Pixel* p_start, Pixel* p_stop, bool* dragging);

#endif

/* END FILE */
