// QUADTREE VISUALIZER MAIN FILE
// - JAMES DELEON

#include <time.h>
#include "point.h"
#include "quadtree.h"
#include "renderwindow.h"

// this file will display a window and with a cli menu
// ui functions:
//

unsigned int generate_coordinate();

int main(int argc, char* argv[])
{
	srand(time(NULL));
	SDL_Object* window = NULL;
	SDL_Event event;
	bool running;

	QuadTree* qtree = NULL;
	Sector* sector = NULL;
	Point* center = NULL;

	center = build_point(DIM / 2, DIM / 2);
	sector = build_sector(center, DIM / 2);
	qtree = build_quadtree(sector);

	window = initialize_SDL();

	running = true;
	while(running == true)
	{
		unsigned int x, y;
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT) {running = false;}
			if(event.type == SDL_MOUSEBUTTONDOWN)
			{
				x = event.button.x;
				y = event.button.y;
				Point* p = build_point(x, y);
				insert(qtree, p);
			}
			if(event.type == SDL_KEYDOWN)
			{
				if(event.key.keysym.sym == SDLK_SPACE)
				{
					for(int i = 0; i < 100; i++)
					{
						x = generate_coordinate();
						y = generate_coordinate();
						Point* p = build_point(x, y);
						insert(qtree, p);
					}
				}
			}
		}

		// update game state
		SDL_SetRenderDrawColor(window -> renderer, 0, 0, 0, 255);
		SDL_RenderClear(window -> renderer);

		// draw to window
		draw_qtree(window, qtree);
		SDL_RenderPresent(window -> renderer);
	}

	destroy_quadtree(qtree);
	cleanup_SDL(window);
	return 0;
}

unsigned int generate_coordinate()
{
	int lower = 0;
	int upper = DIM;

	int random_num = (rand() % (upper - lower + 1)) + lower;
	return random_num;
}

