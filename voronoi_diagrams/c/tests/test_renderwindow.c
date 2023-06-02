// SDL2 RENDERER TEST FILE
// - JAMES DELEON

#include <time.h>
#include "site.h"
#include "quadtree.h"
#include "renderwindow.h"

Site* generate_random_site()
{
	unsigned int x, y, lower = 0, upper = DIM;

	x = (rand() % (upper - lower + 1)) + lower;
	y = (rand() % (upper - lower + 1)) + lower;
	Site* rand_site = build_site(x, y, true);
	print_site(rand_site);
	return rand_site;
}

int main(int argc, char* argv[])
{
	srand(time(NULL));
	SDL_Object* window = NULL;
	SDL_Event event;
	Site* vor_sites[VOR_NUM];
	bool running, restart;

	QuadTree* qtree = NULL;
	Sector* sector = NULL;
	Pixel* center = NULL;

	center = build_pixel(DIM / 2, DIM / 2);
	sector = build_sector(center, DIM / 2);
	qtree = build_quadtree(sector);

	window = initialize_SDL();
	SDL_SetRenderDrawColor(window -> renderer, 0, 0, 0, 255);

	// create some random voronoi sites
	for(int i = 0; i < VOR_NUM; i++)
	{
		vor_sites[i] = generate_random_site();
	}

	// draw
	draw_voronoi(window, qtree, vor_sites);
	SDL_RenderPresent(window -> renderer);
	print_quadtree(qtree);

	printf("\nDONE!\n");

	restart = false;
	running = true;
	while(running == true)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT) {running = false;}
			if(event.type == SDL_KEYDOWN)
			{
				if(event.key.keysym.sym == SDLK_SPACE)
				{
					restart = true;
				}
			}
		}
		
		if(restart == true)
		{
			break; //TODO
		}
	}

	// destroy voronoi sites
	for(int i = 0; i < VOR_NUM; i++)
	{
		destroy_site(vor_sites[i]);
	}
	destroy_quadtree(qtree);
	cleanup_SDL(window);

	return 0;
}

