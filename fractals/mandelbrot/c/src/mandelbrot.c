// MANDELBROT ENGINE SOURCE FILE
// - JAMES DELEON

#include "mandelbrot.h"

Dimensions* build_map(long double x_min, long double x_max, long double y_min, long double y_max)
{
	Dimensions* new_map = NULL;
	new_map = (Dimensions*)malloc(sizeof(Dimensions));
	
	if(new_map == NULL)
	{
		printf("Error allocating map!\n");
		return NULL;
	}
	new_map -> x_min = x_min;
	new_map -> x_max = x_max;
	new_map -> y_min = y_min;
	new_map -> y_max = y_max;
	return new_map;
}

void print_map(Dimensions* map)
{
	printf("=== NW: (%Lf, %Lf)\n", map -> x_min, map -> y_min);
	printf("=== NE: (%Lf, %Lf)\n", map -> x_max, map -> y_min);
	printf("=== SW: (%Lf, %Lf)\n", map -> x_min, map -> y_max);
	printf("=== SE: (%Lf, %Lf)\n", map -> x_max, map -> y_max);
}

void destroy_map(Dimensions* map)
{
	free(map);
}

Site* build_site(unsigned int x, unsigned int y)
{
	Site* new_site = NULL;

	new_site = (Site*)malloc(sizeof(Site));
	if(new_site == NULL)
	{
		printf("Error allocating a site!\n");
		return NULL;
	}
	new_site -> x = x;
	new_site -> y = y;
	new_site -> iterations = 0;
	return new_site;
}

void print_site(Site* site)
{
	char sym;
	
	sym = (site -> iterations) ? '#' : ' ';
	printf("%c", sym);
}

void destroy_site(Site* site)
{
	if(site == NULL) {return;}
	free(site);
}

/*
Site* build_zplane()
{
	Site* new_zplane[DIM][DIM];

	for(int y = 0; y < DIM; y++)
	{
		for(int x = 0; x < DIM; x++)
		{
			new_zplane[x][y] = build_site(x, y);
		}
	}
	return new_zplane;
}

void print_zplane(Site** zplane) {}

void destroy_zplane(Site** zplane)
{
	if(zplane == NULL) {return;}
	for(int i = 0; i < DIM; i++)
	{
		Site* temp = zplane[i];
		destroy_site(temp);
	}
	free(zplane);
}
*/

long double scale_x(Dimensions* map, unsigned int pix_x)
{
	long double scale_factor;

	scale_factor = (long double)((WIDTH - 1) / (map -> x_max - map -> x_min));
	return (map -> x_min) + pix_x / scale_factor;
}

long double scale_y(Dimensions* map, unsigned int pix_y)
{
	long double scale_factor;
	
	scale_factor = (long double)((HEIGHT - 1) / (map -> y_max - map -> y_min));
	return (map -> y_min) + pix_y / scale_factor;
}

long double z_magnitude(Complex z)
{
	return (z.real * z.real) + (z.imag * z.imag);
}

int mandelbrot(Dimensions* map, Site* pixel, int iter_offset)
{
	long double x0, y0, x_temp;
	Complex iter;
	iter.real = 0;
	iter.imag = 0;

	pixel -> z.real = scale_x(map, pixel -> x);
	pixel -> z.imag = scale_y(map, pixel -> y);
	while(z_magnitude(iter) < 4 && pixel -> iterations < (MAX_ITERATIONS + iter_offset))
	{
		x_temp = pixel -> z.real + ((iter.real * iter.real) - (iter.imag * iter.imag));
		iter.imag = pixel -> z.imag + (2 * iter.real * iter.imag);
		iter.real = x_temp;
		pixel -> iterations++;
	}
	return pixel -> iterations;
}


