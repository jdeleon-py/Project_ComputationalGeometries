// SDL2 RENDERER SOURCE FILE
// - JAMES DELEON

#include "renderwindow.h"

SDL_Object* initialize_SDL()
{
	const char* title = "Mandelbrot Set Explorer";
	SDL_Object* new_image;
	new_image = (SDL_Object*)malloc(sizeof(SDL_Object));

	new_image = define_window(new_image, title);
	new_image = define_renderer(new_image);
	new_image = define_texture(new_image, "placeholder.txt");
	return new_image;
}

SDL_Object* define_window(SDL_Object* image, const char* title)
{
	SDL_Window* new_window;

	new_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DIM, DIM, SDL_WINDOW_OPENGL);
	if(new_window == NULL)
	{
		printf("Error... could not create window: %s\n", SDL_GetError());
		return NULL;
	}
	image -> window = new_window;
	return image;
}

SDL_Object* define_renderer(SDL_Object* image)
{
	SDL_Renderer* new_renderer;

	new_renderer = SDL_CreateRenderer(image -> window, -1, SDL_RENDERER_ACCELERATED);
	if(new_renderer == NULL)
	{
		printf("Error... could not create renderer: %s\n", SDL_GetError());
		return NULL;
	}
	image -> renderer = new_renderer;
	return image;
}

SDL_Object* define_texture(SDL_Object* image, char* filename)
{
	//TODO: implement as a separate struct
	image -> texture = NULL;
	return image;
}

bool click_and_drag(SDL_Object* image, SDL_Event event, Pixel* p_start, Pixel* p_stop, bool* dragging)
{
	switch(event.type)
	{
		case SDL_MOUSEBUTTONDOWN:
			if(event.button.button == SDL_BUTTON_LEFT)
			{
				p_start -> x = event.button.x;
				p_start -> y = event.button.y;
            	*dragging = true;        
			}
			break;

		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				*dragging = false;  // Stop dragging
				p_stop -> x = event.button.x;
				p_stop -> y = p_start -> y + (p_stop -> x - p_start -> x);
				draw_zoom_window(image, event, p_start, p_stop);
				SDL_RenderPresent(image -> renderer);
			}
			return true;

		case SDL_MOUSEMOTION:
			// If dragging, draw the window encompassing the selected region
			if(*dragging == true)
			{
				//printf("position of cursor: (%d, %d)\n", event.button.x, event.button.y);
			}
			break;

		default: break;
    }
    return false;
}

void draw_zoom_window(SDL_Object* image, SDL_Event event, Pixel* p_start, Pixel* p_stop)
{
	SDL_SetRenderDrawColor(image -> renderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(image -> renderer, p_start -> x, p_start -> y, p_start -> x, p_stop -> y);
	SDL_RenderDrawLine(image -> renderer, p_start -> x, p_start -> y, p_stop -> x, p_start -> y);
	SDL_RenderDrawLine(image -> renderer, p_stop -> x, p_start -> y, p_stop -> x, p_stop -> y);
	SDL_RenderDrawLine(image -> renderer, p_start -> x, p_stop -> y, p_stop -> x, p_stop -> y);
}

void draw_site(SDL_Object* image, Site* site, int offset)
{
	if(site -> iterations < MAX_ITERATIONS + offset)
	{
		Color color = map_color_pixel(map_inferno, site -> iterations);
		SDL_SetRenderDrawColor(image -> renderer, color.R, color.G, color.B, 255);
	}
	else
	{
		SDL_SetRenderDrawColor(image -> renderer, 0, 0, 0, 255);
	}
	SDL_RenderDrawPoint(image -> renderer, site -> pix.x, site -> pix.y);
}

void cleanup_SDL(SDL_Object* image)
{
	SDL_DestroyWindow(image -> window);
	SDL_DestroyRenderer(image -> renderer);
	free(image);
}

/* END FILE */
