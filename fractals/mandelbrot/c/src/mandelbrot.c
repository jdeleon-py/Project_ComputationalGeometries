// MANDELBROT ENGINE SOURCE FILE
// - JAMES DELEON

#include "mandelbrot.h"

Site* build_site()
{
	Site* new_site = NULL;

	new_site = (Site*)malloc(sizeof(Site));
	if(new_site == NULL)
	{
		printf("Error allocating a site!\n");
		return NULL;
	}
	new_site -> z.real = 0;
	new_site -> z.imag = 0;
	new_site -> color.R = 0;
	new_site -> color.G = 0;
	new_site -> color.B = 0;
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

Site** build_zplane()
{
	Site** new_zplane = NULL;

	new_zplane = (Site**)malloc(DIM_TEST * sizeof(Site*));
	if(new_zplane == NULL)
	{
		printf("Error allocating a z-plane!\n");
		return NULL;
	}
	for(int i = 0; i < DIM_TEST; i++)
	{
		new_zplane[i] = build_site();
	}
	return new_zplane;
}

void print_zplane(Site** zplane) {}

void destroy_zplane(Site** zplane)
{
	if(zplane == NULL) {return;}
	for(int i = 0; i < DIM_TEST; i++)
	{
		Site* temp = zplane[i];
		destroy_site(temp);
	}
	free(zplane);
}

long double scale_x(long double pix_x)
{
	long double scale_factor;

	scale_factor = (long double)((WIDTH - 1) / (X_MAX - X_MIN));
	return X_MIN + pix_x / scale_factor;
}

long double scale_y(long double pix_y)
{
	long double scale_factor;
	
	scale_factor = (long double)((HEIGHT - 1) / (Y_MAX - Y_MIN));
	return Y_MIN + pix_y / scale_factor;
}

long double z_magnitude(Complex z)
{
	return (z.real * z.real) + (z.imag * z.imag);
}

int mandelbrot(Site* pixel)
{
	long double x0, y0, x_temp;
	Complex iter;
	iter.real = 0;
	iter.imag = 0;

	x0 = scale_x(pixel -> z.real);
	y0 = scale_y(pixel -> z.imag);
	while(z_magnitude(iter) < 4 && pixel -> iterations < MAX_ITERATIONS)
	{
		x_temp = x0 + ((iter.real * iter.real) - (iter.imag * iter.imag));
		iter.imag = y0 + (2 * iter.real * iter.imag);
		iter.real = x_temp;
		pixel -> iterations++;
	}
	return pixel -> iterations;
}


