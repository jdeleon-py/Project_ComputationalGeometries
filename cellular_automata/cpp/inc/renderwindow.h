// RENDERWINDOW HEADER FILE
// - JAMES DELEON

#ifndef __RENDERWINDOW_H__
#define __RENDERWINDOW_H__

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "grid.h"

#define WIDTH  		512
#define HEIGHT 		512
#define CELL_WIDTH	(int)(WIDTH / DIM)
#define CELL_HEIGHT	(int)(HEIGHT / DIM)

class RenderWindow
{
public:
	RenderWindow(const char* title, int width, int height);
	SDL_Texture* LoadTexture(const char* p_filePath);
	
	void click_update(SDL_Event event);
	void draw();
	void cleanup();

	Grid grid;

private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
};

#endif
