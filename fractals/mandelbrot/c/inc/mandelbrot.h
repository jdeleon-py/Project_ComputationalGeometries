// MANDELBROT ENGINE HEADER FILE
// - JAMES DELEON

#ifndef __MANDELBROT_H__
#define __MANDELBROT_H__

#include <stdio.h>
#include <stdlib.h>
#include "color.h"

#define MAX_ITERATIONS   500
#define DIM_TEST         128

#define X_MIN             -0.3
#define X_MAX              0.3
#define Y_MIN             -1
#define Y_MAX             -0.6

#define WIDTH            600
#define HEIGHT           400

/* MANDELBROT MATH
 * -> let n be the range of iterative calculations
 * -> z_(n+1) = z_n^2 + c
 * -> where z = x + jy
 * -> where c corresponds to the current pixel's location (complex)
 * -> where z_0 = 0
 *
 * -> z_(n+1) = (x + jy)^2 + c
 * -> z_(n+1) = (x^2 + y^2) + 2xyj + (x_c + jy_c)
 * -> z_(n+1) = (x^2 + y^2 + x_c) + j(2xy + y_c)
 * -> if mag(z_(n+1)) > threshold, then can assume divergence occurs at z_n
 */

extern const Color map_inferno[];

typedef struct Complex
{
	long double real;
	long double imag;
} Complex;

// QUADTREE NODE (PIXEL)
typedef struct Site
{
	Complex z;
	Color color;
	int iterations;
} Site;

// note that the most time is spent calculating along the edges of the curve

// Complex number handling
long double z_magnitude(Complex z);

// Generalized site handling
Site* build_site();
void print_site(Site* site);
void destroy_site(Site* site);

// Z-Plane Handling
Site** build_zplane();
void print_zplane(Site** zplane);
void destroy_zplane(Site** zplane);

// Mandelbrot API's
long double scale_x(long double pix_x);
long double scale_y(long double pix_y);
int mandelbrot(Site* pixel);

#endif
