// VORONOI QT CELL AREA CALCULATIONS TEST PROGRAM
// - JAMES DELEON

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "site.h"
#include "quadtree.h"

#define DIM 512

int clamp(int value, int min, int max);
double generate_normal(double mean, double stddev);
Site* generate_normal_random_site();
Site* generate_uniform_random_site();
double get_mean_cell_area(Site* vor_sites[], int arr_n);
double get_svar(Site* vor_sites[], double mean, int arr_n);
void build_voronoi(QuadTree* qtree, Site* vor_sites[]);

int main(int argc, char* argv[])
{
	unsigned int seed;
	seed = (argc > 1) ? atoi(argv[1]) : time(NULL);
	srand(seed);

	Site* vor_sites[VOR_NUM];
	bool running, restart;

	QuadTree* qtree = NULL;
	Sector* sector = NULL;
	Pixel* center = NULL;

	center = build_pixel(DIM / 2, DIM / 2);
	sector = build_sector(center, DIM / 2);
	qtree = build_quadtree(sector);

	// create some random voronoi sites
	for(int i = 0; i < VOR_NUM; i++)
	{
		//vor_sites[i] = generate_uniform_random_site();
		vor_sites[i] = generate_normal_random_site();
	}

	// draw
	build_voronoi(qtree, vor_sites);
	//print_quadtree(qtree);

	// print cell areas for each cell in diagram
	for(int i = 0; i < VOR_NUM; i++)
	{
		//print_site(vor_sites[i]);
	}

	double smean = get_mean_cell_area(vor_sites, VOR_NUM);
	double svar = get_svar(vor_sites, smean, VOR_NUM);
	//printf("Approximate Mean Cell Area: %d sq. px\n", (DIM * DIM) / VOR_NUM);
	//printf("Mean Cell Area: %f sq. px\n", smean);
	//printf("Cell Area Variance: %f sq. px\n", svar);
	printf("%f\n", svar);

	//printf("\nDONE!\n");

	// destroy voronoi sites
	for(int i = 0; i < VOR_NUM; i++)
	{
		destroy_site(vor_sites[i]);
	}
	destroy_quadtree(qtree);
	return 0;
}

// Clamp function
int clamp(int value, int min, int max)
{
	if (value < min) return min;
	if (value > max) return max;
	return value;
}

// Box-Muller method for normal distribution
double generate_normal(double mean, double stddev)
{
	double u1 = (rand() + 1.0) / (RAND_MAX + 2.0);
	double u2 = (rand() + 1.0) / (RAND_MAX + 2.0);
	double z0 = sqrt(-2.0 * log(u1)) * cos(2 * M_PI * u2);
	return z0 * stddev + mean;
}

Site* generate_normal_random_site()
{
	// Adjust mean and stddev as needed
	double mean = DIM / 2.0;
	double stddev = DIM / 6.0;  // ~99.7% of values within [0, DIM]

	// Generate normal distributed and clamped x and y
	int x = clamp((int)round(generate_normal(mean, stddev)), 0, DIM);
	int y = clamp((int)round(generate_normal(mean, stddev)), 0, DIM);

	Site* rand_site = build_site(x, y, true);
	return rand_site;
}

/*
 * - uniform random distribution 2D [0, DIM] 
*/
Site* generate_uniform_random_site()
{
	unsigned int x, y, lower = 0, upper = DIM;

	x = (rand() % (upper - lower + 1)) + lower;
	y = (rand() % (upper - lower + 1)) + lower;
	Site* rand_site = build_site(x, y, true);
	return rand_site;
}

/**
 * - this function will calculate the mean of an array of
 * voronoi sites with respect to the cell area of the site
*/
double get_mean_cell_area(Site* vor_sites[], int arr_n)
{
	if(vor_sites == NULL)
	{
		printf("Error - cannot find vor_sites;\n");
		return -1.0;
	}
	int acc = 0;
	for(int i = 0; i < arr_n; i++)
	{
		acc += vor_sites[i] -> cell_area;
	}
	return (double)(acc / arr_n);
}

/**
 * - this function will calculate the 
*/
double get_svar(Site* vor_sites[], double mean, int arr_n)
{
	if (vor_sites == NULL)
	{
		printf("Error - cannot find vor sites;\n");
		return -1.0;
	}

	double acc = 0.0;
	for (int i = 0; i < arr_n; i++)
	{
		double temp_area = (double)(vor_sites[i] -> cell_area);
		acc += pow(temp_area - mean, 2);
	}

	return acc / (arr_n - 1); // sample variance: denominator = n - 1
}

/**
 * - extracted from renderwindow src file
 * (equivalent functionality, but no rendering necessary)
*/
void build_voronoi(QuadTree* qtree, Site* vor_sites[])
{
	if(qtree == NULL || vor_sites == NULL)
	{
		printf("Error - cannot find qtree or vor_sites;\n");
		return;
	}
	corner_scan(qtree -> boundary, vor_sites);

	if(qtree -> boundary -> radius == 1)
	{
		// draw nw
		Site* boundary_nw = qtree -> boundary -> corners[NW];
		Pixel* nw_cell_pos = boundary_nw -> pixel;
		Color nw_cell_color = boundary_nw -> color;
		boundary_nw -> closest_site -> cell_area += 1;

		// draw ne
		Site* boundary_ne = qtree -> boundary -> corners[NE];
		Pixel* ne_cell_pos = boundary_ne -> pixel;
		Color ne_cell_color = boundary_ne -> color;
		boundary_ne -> closest_site -> cell_area += 1;

		// draw sw
		Site* boundary_sw = qtree -> boundary -> corners[SW];
		Pixel* sw_cell_pos = boundary_sw -> pixel;
		Color sw_cell_color = boundary_sw -> color;
		boundary_sw -> closest_site -> cell_area += 1;

		// draw se
		Site* boundary_se = qtree -> boundary -> corners[SE];
		Pixel* se_cell_pos = boundary_se -> pixel;
		Color se_cell_color = boundary_se -> color;
		boundary_se -> closest_site -> cell_area += 1;
		return;
	}
	else if(corner_check(qtree -> boundary) == true)
	{
		Sector* sec = qtree -> boundary;
		unsigned int rad = sec -> radius;
		
		unsigned int x_min = qtree -> boundary -> corners[0] -> pixel -> x;
		unsigned int x_max = qtree -> boundary -> corners[1] -> pixel -> x;
		unsigned int y_min = qtree -> boundary -> corners[0] -> pixel -> y;
		unsigned int y_max = qtree -> boundary -> corners[2] -> pixel -> y;
		
		sec -> corners[NW] -> closest_site -> cell_area += 4 * rad * rad;
		for(int x = x_min; x < x_max; x++)
		{
			for(int y = y_min; y < y_max; y++)
			{
				Color site_color = qtree -> boundary -> corners[0] -> color;
			}
		}
		return;
	}
	else if(qtree -> divided == false)
	{
		subdivide(qtree);
		build_voronoi(qtree -> nw, vor_sites);
		build_voronoi(qtree -> ne, vor_sites);
		build_voronoi(qtree -> sw, vor_sites);
		build_voronoi(qtree -> se, vor_sites);
	}
}

/* END FILE */