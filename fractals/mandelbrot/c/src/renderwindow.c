// SDL2 RENDERER SOURCE FILE
// - JAMES DELEON

#include "renderwindow.h"

SDL_Object* initialize_SDL()
{
	const char* title = "Mandelbrot Set Visualizer";
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

bool click_and_drag(SDL_Event event, Dimensions* map, bool* dragging)
{
	unsigned int px0, px1, py0, py1;
	long double mx0, mx1, my0, my1;
	Dimensions* temp_map = map;
	switch(event.type)
	{
		case SDL_MOUSEBUTTONDOWN:
			if(event.button.button == SDL_BUTTON_LEFT)
			{
				px0 = event.button.x;
				py0 = event.button.y;
				mx0 = scale_x(map, px0);
				my0 = scale_y(map, py0);
				temp_map -> x_min = mx0;
				temp_map -> y_min = my0;
            	*dragging = true;        
			}
			break;

		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				*dragging = false;  // Stop dragging
				px1 = event.button.x;
				mx1 = scale_x(map, px1);
				temp_map -> x_max = mx1;
				my1 = temp_map -> y_min + (temp_map -> x_max - temp_map -> x_min);
				temp_map -> y_max = my1;
			}
			map = temp_map;
			return true;

		case SDL_MOUSEMOTION:
			// If dragging, update the object's position
			/*
			if(*dragging == true)
			{
				printf("position of cursor: (%d, %d)\n", event.button.x, event.button.y);
			}
			*/
			break;

		default: break;
    }
    return false;
}

/*
void draw_point(SDL_Object* image, Point* point)
{
	//SDL_RenderSetScale(image -> renderer, 2, 2); // Increase scale for thicker points
	SDL_SetRenderDrawColor(image -> renderer, 255, 255, 255, 255);
	SDL_RenderDrawPoint(image -> renderer, point -> x, point -> y);
}
*/

void draw_site(SDL_Object* image, Site* site)
{
	if(site -> iterations < MAX_ITERATIONS)
	{
		Color color = map_color_pixel(map_inferno, site -> iterations);
		//int color = 255 - (256 / (site -> iterations));
		SDL_SetRenderDrawColor(image -> renderer, color.R, color.G, color.B, 255);
	}
	else
	{
		SDL_SetRenderDrawColor(image -> renderer, 0, 0, 0, 255);
	}
	SDL_RenderDrawPoint(image -> renderer, site -> x, site -> y);
}

void draw_line_V(SDL_Object* image, unsigned int cx, unsigned int cy, unsigned int r)
{
	SDL_SetRenderDrawColor(image -> renderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(image -> renderer, cx, cy - r, cx, cy + r);
}

void draw_line_H(SDL_Object* image, unsigned int cx, unsigned int cy, unsigned int r)
{
	SDL_SetRenderDrawColor(image -> renderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(image -> renderer, cx - r, cy, cx + r, cy);
}

/*
void draw_qtree(SDL_Object* image, QuadTree* qtree)
{
	unsigned int centerx, centery, radius;
	int point_num;

	centerx = qtree -> boundary -> center -> x;
	centery = qtree -> boundary -> center -> y;
	radius = qtree -> boundary -> radius;

	point_num = query_points(qtree);
	for(int i = 0; i < point_num; i++)
	{
		Point* p = qtree -> points[i];
		draw_point(image, p);
	}

	if(qtree -> divided == true)
	{
		// drawing a vertical qtree boundary line
		draw_line_V(image, centerx, centery, radius);

		// drawing a horizontal qtree boundary line
		draw_line_H(image, centerx, centery, radius);

		draw_qtree(image, qtree -> nw);
		draw_qtree(image, qtree -> ne);
		draw_qtree(image, qtree -> sw);
		draw_qtree(image, qtree -> se);
	}
}
*/

void cleanup_SDL(SDL_Object* image)
{
	SDL_DestroyWindow(image -> window);
	SDL_DestroyRenderer(image -> renderer);
	free(image);
}
