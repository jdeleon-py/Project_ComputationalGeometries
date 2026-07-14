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
	if(SDL_Init(SDL_INIT_VIDEO > 0))
	{
		printf("SDL_Init has failed. SDL_Error: %s\n", SDL_GetError());
		return 0;
	}
	if(!IMG_Init(IMG_INIT_PNG))
	{
		printf("IMG_init has failed. SDL_Error: %s\n", SDL_GetError());
		return 0;
	}

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
	//SDL_RenderPresent(window -> renderer);
	// print_quadtree(qtree);

	SDL_SetRenderDrawColor(window->renderer, 0, 0, 0, 255);
	SDL_RenderClear(window->renderer);

	/* Build sites and quadtree. */
	draw_voronoi(window, qtree, vor_sites);

	/* Only one presentation after drawing finishes. */
	SDL_RenderPresent(window->renderer);

	printf("\nDONE!\n");

	restart = false;
	running = true;
	while(running == true)
	{
		while(SDL_PollEvent(&event) != 0)
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

	cleanup_SDL(window);
	destroy_quadtree(qtree);
	// destroy voronoi sites
	for(int i = 0; i < VOR_NUM; i++)
	{
		destroy_site(vor_sites[i]);
	}
	SDL_Quit();
	return 0;
}

