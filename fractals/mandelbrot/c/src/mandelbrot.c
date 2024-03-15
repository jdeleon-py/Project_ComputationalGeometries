// MANDELBROT ENGINE SOURCE FILE
// - JAMES DELEON

#include "mandelbrot.h"

/*
 * allocation function for a canvas object
*/
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

/*
 * prints dimensions of a canvas object
*/
void print_map(Dimensions* map)
{
	printf("=== NW: (%Lf, %Lf)\n", map -> x_min, map -> y_min);
	printf("=== NE: (%Lf, %Lf)\n", map -> x_max, map -> y_min);
	printf("=== SW: (%Lf, %Lf)\n", map -> x_min, map -> y_max);
	printf("=== SE: (%Lf, %Lf)\n", map -> x_max, map -> y_max);
}

/*
 * deallocation of a canvas object
*/
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
	new_site -> pix.x = x;
	new_site -> pix.y = y;
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

/*
 * computes the magnitude of a complex number
 * z = x + jy
 * |z|^2 = (x + jy)(x - jy) = (x^2 + y^2)
*/
long double z_magnitude(Complex z)
{
	return (z.real * z.real) + (z.imag * z.imag);
}

/* MANDELBROT MATH
 * -> let n be the range of iterative calculations
 * -> z_(n+1) = z_n^2 + c
 * -> where z = x + jy
 * -> where c corresponds to the current pixel's location (complex a+bj)
 * -> where z_0 = 0
 *
 * -> z_(n+1) = (x + jy)^2 + c
 * -> z_(n+1) = (x^2 + y^2) + 2xyj + (x_c + jy_c)
 * -> z_(n+1) = (x^2 + y^2 + x_c) + j(2xy + y_c)
 * -> if mag(z_(n+1)) > threshold, then can assume divergence occurs at z_n
*/
int mandelbrot(Dimensions* map, Site* pixel, int iter_offset)
{
	long double x0, y0, x_temp;
	Complex iter;
	iter.real = 0;
	iter.imag = 0;

	pixel -> z.real = scale_x(map, pixel -> pix.x);
	pixel -> z.imag = scale_y(map, pixel -> pix.y);
	while(z_magnitude(iter) < 2 && pixel -> iterations < (MAX_ITERATIONS + iter_offset))
	{
		x_temp = pixel -> z.real + ((iter.real * iter.real) - (iter.imag * iter.imag));
		iter.imag = pixel -> z.imag + (2 * iter.real * iter.imag);
		iter.real = x_temp;
		pixel -> iterations++;
	}
	return pixel -> iterations;
}

/* END FILE */