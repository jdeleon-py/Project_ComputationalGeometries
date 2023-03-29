// RENDERWINDOW HEADER FILE

#ifndef __RENDERWINDOW_H
#define __RENDERWINDOW_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "grid.h"


#define WIDTH  		(const int)(512)
#define HEIGHT 		(const int)(512)

#define CELL_WIDTH	(int)(WIDTH / DIM)
#define CELL_HEIGHT	(int)(HEIGHT / DIM)

class RenderWindow
{
	public:
		RenderWindow(const char* title, int width, int height);
		SDL_Texture* LoadTexture(const char* p_filePath);
		void draw();
		void cleanup();

		Grid grid;

	private:
		SDL_Window* window = NULL;
		SDL_Renderer* renderer = NULL;
};

#endif
