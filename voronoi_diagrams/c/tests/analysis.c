// ALGORITHM COMPLEXITY ANALYSIS TEST FILE
// - JAMES DELEON

#include <time.h>

#include "site.h"
#include "renderwindow.h"
#include "quadtree.h" 

// functional encapsulation of naive algorithm
void algo_naive(SDL_Object* image, Site* vor_sites[], long int* dist_op_count, long int* rend_op_count);

// functional encapsulation of QT algorithm
// override or transfer (draw_voronoi()) func from renderwindow.c
void algo_qt(SDL_Object* image, QuadTree* qtree, Site* vor_sites[], long int* dist_op_count, long int* rend_op_count);
void qt_scanner(Sector* sector, Site* vor_sites[], long int* dist_op_count, long int* rend_op_count);
Site* generate_random_site();

int main(int argc, char* argv[])
{
	srand(time(NULL));
	SDL_Object* window = NULL;
	Site* vor_sites[VOR_NUM];

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

	long int dist_op_count = 0;
	long int rend_op_count = 0;

	clock_t start, end;
	double cpu_time_used;

	start = clock();  // Record the starting time

	// draw
	algo_naive(window, vor_sites, &dist_op_count, &rend_op_count);
	//algo_qt(window, qtree, vor_sites, &dist_op_count, &rend_op_count);
	SDL_RenderPresent(window -> renderer);
	
	end = clock();  // Record the ending time
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	printf("Execution time: %f seconds\n", cpu_time_used);
	printf("Distance calculations: %ld\n", dist_op_count);
	printf("Render calculations: %ld\n", rend_op_count);
	printf("Total Calculations: %ld\n", dist_op_count + rend_op_count);
	printf("QT Memory: %zu bytes.\n", get_qtree_size(qtree));
	
	printf("\nDONE!\n");


	// destroy voronoi sites
	for(int i = 0; i < VOR_NUM; i++)
	{
		destroy_site(vor_sites[i]);
	}
	destroy_quadtree(qtree);
	cleanup_SDL(window);

	return 0;
}




// Utilities
// void render_func();
// void distance_func();

Site* generate_random_site()
{
	unsigned int x, y, lower = 0, upper = DIM;

	x = (rand() % (upper - lower + 1)) + lower;
	y = (rand() % (upper - lower + 1)) + lower;
	Site* rand_site = build_site(x, y, true);
	return rand_site;
}

void algo_naive(SDL_Object* image, Site* vor_sites[], long int* dist_op_count, long int* rend_op_count)
{
	double dist;
	size_t size = 0;

	// distance and render calculations
	for(int j = 0; j < DIM; j++)
	{
		for(int i = 0; i < DIM; i++)
		{
			Site* pixel = build_site(i, j, false);
			for(int p = 0; p < VOR_NUM; p++)
			{
				dist = get_distance(pixel, vor_sites[p]);
				if(dist < pixel -> min_distance)
				{
					pixel -> closest_site = vor_sites[p];
					pixel -> min_distance = dist;
				}
				(*dist_op_count)++;
			}
			Color pix_color = pixel -> closest_site -> color;
			SDL_SetRenderDrawColor(image -> renderer, pix_color.R, pix_color.G, pix_color.B, 255);
			SDL_RenderDrawPoint(image -> renderer, i, j);
			//SDL_RenderPresent(image -> renderer);
			(*rend_op_count)++;
			size += get_site_size(pixel);

			destroy_site(pixel);
		}
	}
	printf("Naive Size: %zu bytes.\n", size);
}

// a clone of draw_voronoi();
void algo_qt(SDL_Object* image, QuadTree* qtree, Site* vor_sites[], long int* dist_op_count, long int* rend_op_count)
{
	if(qtree == NULL)
	{
		printf("Something is wrong!\n");
		return;
	}
	qt_scanner(qtree -> boundary, vor_sites, dist_op_count, rend_op_count);

	if(qtree -> boundary -> radius == 1)
	{
		// draw nw
		Pixel* nw_cell_pos = qtree -> boundary -> corners[NW] -> pixel;
		Color nw_cell_color = qtree -> boundary -> corners[NW] -> closest_site -> color;
		SDL_SetRenderDrawColor(image -> renderer, nw_cell_color.R, nw_cell_color.G, nw_cell_color.B, 255);
		SDL_RenderDrawPoint(image -> renderer, nw_cell_pos -> x, nw_cell_pos -> y);
		SDL_RenderPresent(image -> renderer);

		// draw ne
		Pixel* ne_cell_pos = qtree -> boundary -> corners[NE] -> pixel;
		Color ne_cell_color = qtree -> boundary -> corners[NE] -> closest_site -> color;
		SDL_SetRenderDrawColor(image -> renderer, ne_cell_color.R, ne_cell_color.G, ne_cell_color.B, 255);
		SDL_RenderDrawPoint(image -> renderer, ne_cell_pos -> x, ne_cell_pos -> y);
		SDL_RenderPresent(image -> renderer);

		// draw sw
		Pixel* sw_cell_pos = qtree -> boundary -> corners[SW] -> pixel;
		Color sw_cell_color = qtree -> boundary -> corners[SW] -> closest_site -> color;
		SDL_SetRenderDrawColor(image -> renderer, sw_cell_color.R, sw_cell_color.G, sw_cell_color.B, 255);
		SDL_RenderDrawPoint(image -> renderer, sw_cell_pos -> x, sw_cell_pos -> y);
		SDL_RenderPresent(image -> renderer);

		// draw se
		Pixel* se_cell_pos = qtree -> boundary -> corners[SE] -> pixel;
		Color se_cell_color = qtree -> boundary -> corners[SE] -> closest_site -> color;
		SDL_SetRenderDrawColor(image -> renderer, se_cell_color.R, se_cell_color.G, se_cell_color.B, 255);
		SDL_RenderDrawPoint(image -> renderer, se_cell_pos -> x, se_cell_pos -> y);
		SDL_RenderPresent(image -> renderer);

		(*rend_op_count) += 4;
		return;
	}
	else if(corner_check(qtree -> boundary) == true)
	{
		unsigned int x_min = qtree -> boundary -> corners[0] -> pixel -> x;
		unsigned int x_max = qtree -> boundary -> corners[1] -> pixel -> x;
		unsigned int y_min = qtree -> boundary -> corners[0] -> pixel -> y;
		unsigned int y_max = qtree -> boundary -> corners[2] -> pixel -> y;

		for(int x = x_min; x < x_max + 1; x++)
		{
			for(int y = y_min; y < y_max + 1; y++)
			{
				Color site_color = qtree -> boundary -> corners[0] -> closest_site -> color;
				SDL_SetRenderDrawColor(image -> renderer, site_color.R, site_color.G, site_color.B, 255);
				SDL_RenderDrawPoint(image -> renderer, x, y);
				//SDL_RenderPresent(image -> renderer);
			}
			//SDL_RenderPresent(image -> renderer);
		}
		SDL_RenderPresent(image -> renderer);
		(*rend_op_count)++;
		return;
	}
	else if(qtree -> divided == false)
	{
		subdivide(qtree);
		algo_qt(image, qtree -> nw, vor_sites, dist_op_count, rend_op_count);
		algo_qt(image, qtree -> ne, vor_sites, dist_op_count, rend_op_count);
		algo_qt(image, qtree -> sw, vor_sites, dist_op_count, rend_op_count);
		algo_qt(image, qtree -> se, vor_sites, dist_op_count, rend_op_count);
	}
}

// a clone of corner_scan()
void qt_scanner(Sector* sector, Site* vor_sites[], long int* dist_op_count, long int* rend_op_count)
{
	if(sector == NULL || vor_sites == NULL) return;
	double nw_dist, ne_dist, sw_dist, se_dist;

	for(int i = 0; i < VOR_NUM; i++)
	{
		nw_dist = get_distance(sector -> corners[NW], vor_sites[i]);
		ne_dist = get_distance(sector -> corners[NE], vor_sites[i]);
		sw_dist = get_distance(sector -> corners[SW], vor_sites[i]);
		se_dist = get_distance(sector -> corners[SE], vor_sites[i]);
		(*dist_op_count) += 4;

		if(nw_dist < sector -> corners[NW] -> min_distance)
		{
			sector -> corners[NW] -> closest_site = vor_sites[i];
			sector -> corners[NW] -> min_distance = nw_dist;
		}
		if(ne_dist < sector -> corners[NE] -> min_distance)
		{
			sector -> corners[NE] -> closest_site = vor_sites[i];
			sector -> corners[NE] -> min_distance = ne_dist;
		}
		if(sw_dist < sector -> corners[SW] -> min_distance)
		{
			sector -> corners[SW] -> closest_site = vor_sites[i];
			sector -> corners[SW] -> min_distance = sw_dist;
		}
		if(se_dist < sector -> corners[SE] -> min_distance)
		{
			sector -> corners[SE] -> closest_site = vor_sites[i];
			sector -> corners[SE] -> min_distance = se_dist;
		}
	}		
}

