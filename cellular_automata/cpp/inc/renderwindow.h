// CA RENDERWINDOW HEADER FILE
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
	
	// click cell operations
	void click_update(SDL_Event event);
	void toggle_cell(int i, int j);
	inline void set_cell(int i, int j) {grid.get_cell(i, j).set_state(1);}   // make cell alive
	inline void clear_cell(int i, int j) {grid.get_cell(i, j).set_state(0);} // make cell dead

	void cli_handler(SDL_Event event, std::string& text);
	void draw();
	void cleanup();

	Grid grid;

private:
	void cli_display();

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
};

#endif

/* END FILE */
