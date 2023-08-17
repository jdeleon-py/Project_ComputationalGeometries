// SDL2 RENDERER SOURCE FILE
// - JAMES DELEON

#include "renderwindow.h"

SDL_Object* initialize_SDL()
{
	const char* title = "Voronoi Diagram Generation with QT Optimization";
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

/*
void draw_site(SDL_Object* image, Site* site, int offset)
{
	if(site -> iterations < (MAX_ITERATIONS + offset))
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
*/

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

void draw_voronoi(SDL_Object* image, QuadTree* qtree, Site* vor_sites[])
{
	if(qtree == NULL)
	{
		printf("Something is wrong!\n");
		return;
	}
	corner_scan(qtree -> boundary, vor_sites);

	if(qtree -> boundary -> radius == 1)
	{
		// draw nw
		Pixel* nw_cell_pos = qtree -> boundary -> corners[NW] -> pixel;
		Color nw_cell_color = qtree -> boundary -> corners[NW] -> closest_site -> color;
		SDL_SetRenderDrawColor(image -> renderer, nw_cell_color.R, nw_cell_color.G, nw_cell_color.B, 255);
		SDL_RenderDrawPoint(image -> renderer, nw_cell_pos -> x, nw_cell_pos -> y);
		//SDL_RenderPresent(image -> renderer);

		// draw ne
		Pixel* ne_cell_pos = qtree -> boundary -> corners[NE] -> pixel;
		Color ne_cell_color = qtree -> boundary -> corners[NE] -> closest_site -> color;
		SDL_SetRenderDrawColor(image -> renderer, ne_cell_color.R, ne_cell_color.G, ne_cell_color.B, 255);
		SDL_RenderDrawPoint(image -> renderer, ne_cell_pos -> x, ne_cell_pos -> y);
		//SDL_RenderPresent(image -> renderer);

		// draw sw
		Pixel* sw_cell_pos = qtree -> boundary -> corners[SW] -> pixel;
		Color sw_cell_color = qtree -> boundary -> corners[SW] -> closest_site -> color;
		SDL_SetRenderDrawColor(image -> renderer, sw_cell_color.R, sw_cell_color.G, sw_cell_color.B, 255);
		SDL_RenderDrawPoint(image -> renderer, sw_cell_pos -> x, sw_cell_pos -> y);
		//SDL_RenderPresent(image -> renderer);

		// draw se
		Pixel* se_cell_pos = qtree -> boundary -> corners[SE] -> pixel;
		Color se_cell_color = qtree -> boundary -> corners[SE] -> closest_site -> color;
		SDL_SetRenderDrawColor(image -> renderer, se_cell_color.R, se_cell_color.G, se_cell_color.B, 255);
		SDL_RenderDrawPoint(image -> renderer, se_cell_pos -> x, se_cell_pos -> y);
		//SDL_RenderPresent(image -> renderer);
		return;
	}
	else if(corner_check(qtree -> boundary) == true)
	{
		unsigned int x_min = qtree -> boundary -> corners[0] -> pixel -> x;
		unsigned int x_max = qtree -> boundary -> corners[1] -> pixel -> x;
		unsigned int y_min = qtree -> boundary -> corners[0] -> pixel -> y;
		unsigned int y_max = qtree -> boundary -> corners[2] -> pixel -> y;

		for(int x = x_min; x < x_max; x++)
		{
			for(int y = y_min; y < y_max; y++)
			{
				Color site_color = qtree -> boundary -> corners[0] -> closest_site -> color;
				SDL_SetRenderDrawColor(image -> renderer, site_color.R, site_color.G, site_color.B, 255);
				SDL_RenderDrawPoint(image -> renderer, x, y);
				//SDL_RenderPresent(image -> renderer);
			}
			//SDL_RenderPresent(image -> renderer);
		}
		//SDL_RenderPresent(image -> renderer);
		return;
	}
	else if(qtree -> divided == false)
	{
		subdivide(qtree);
		draw_voronoi(image, qtree -> nw, vor_sites);
		draw_voronoi(image, qtree -> ne, vor_sites);
		draw_voronoi(image, qtree -> sw, vor_sites);
		draw_voronoi(image, qtree -> se, vor_sites);
	}
}

void cleanup_SDL(SDL_Object* image)
{
	SDL_DestroyWindow(image -> window);
	SDL_DestroyRenderer(image -> renderer);
	free(image);
}
