// MANDELBROT/JULIA ENGINE HEADER FILE
// - JAMES DELEON

#ifndef __MANDELBROT_H__
#define __MANDELBROT_H__

#include <stdio.h>
#include <stdlib.h>
#include "color.h"

#define MAX_ITERATIONS   500
#define DIM              512

#define WIDTH            DIM
#define HEIGHT           DIM

/* CANVAS STRUCTURE DEFINITION */
typedef struct Dimensions
{
	long double x_min, x_max, y_min, y_max;
} Dimensions;

/* PIXEL STRUCTURE DEFINITION */
typedef struct Pixel
{
	unsigned int x, y;
} Pixel;

/* COMPLEX NUMBER DEFINITION */
typedef struct Complex
{
	// Complex z = (real) + j(imag);
	long double real, imag;
} Complex;

/* 
 * CANVAS NODE STRUCTURE DEFINITION
 * - every pixel on the canvas is a site node 
*/
typedef struct Site
{
	Pixel pix;   // for window coordinates
	Complex z;   // for mandelbrot coordinates
	Color color;

	int iterations; // power iteration convergence parameter
} Site;

/*
 * functional descriptions are found in corresponding src file
 *
 * note that the most time is spent calculating along the edges of the curve
*/

// Complex Number Handling
long double z_magnitude(Complex z);

// Mandelbrot/Julia Map Handling
Dimensions* build_map(long double x_min, long double x_max, long double y_min, long double y_max);
void print_map(Dimensions* map);
void destroy_map(Dimensions* map);

// Generalized Site Handling
Site* build_site(unsigned int x, unsigned int y);
void print_site(Site* site);
void destroy_site(Site* site);

// Mandelbrot/Julia API's
long double scale_x(Dimensions* map, unsigned int pix_x);
long double scale_y(Dimensions* map, unsigned int pix_y);
int mandelbrot(Dimensions* map, Site* pixel, int iter_offset);
int julia(Dimensions* map, Site* pixel, Complex seed, int iter_offset);

#endif

/* END FILE */
