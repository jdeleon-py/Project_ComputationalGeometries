// RENDERWINDOW SOURCE FILE

#include "renderwindow.h"

SDL_Image* initialize_SDL()
{
	SDL_Image* new_image;
	new_image = (struct SDL_Image*)malloc(sizeof(struct SDL_Image));

	new_image -> window = define_window();
	new_image -> renderer = define_renderer();
	return new_image;
}

SDL_Window* define_window()
{
	SDL_Window* new_window;

	new_window = SDL_CreateWindow("SDL2 Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);

	if(new_window == NULL)
	{
		printf("Error... could not create window: %s\n", SDL_GetError());
		return NULL;
	}
	return new_window;
}

SDL_Renderer* define_renderer() {}
SDL_Texture* define_texture() {}

void draw() {}

void cleanup_SDL(struct SDL_Image* image)
{
	SDL_DestroyWindow(image -> window);
	// destroy renderer
	free(image);	
}

