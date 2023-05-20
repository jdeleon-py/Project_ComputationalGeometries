// MANDELBROT ENGINE HEADER FILE
// - JAMES DELEON

#ifndef __MANDELBROT_H__
#define __MANDELBROT_H__

#include <stdio.h>
#include <stdlib.h>
#include "color.h"

#define MAX_ITERATIONS   5000
#define DIM              512

#define X_MIN             -2
#define X_MAX              1
#define Y_MIN           -1.5
#define Y_MAX            1.5

#define WIDTH            DIM
#define HEIGHT           DIM

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

typedef struct Complex
{
	long double real;
	long double imag;
} Complex;

// QUADTREE NODE (PIXEL)
typedef struct Site
{
	unsigned int x;
	unsigned int y;
	Complex z;

	Color color;
	int iterations;
} Site;

// note that the most time is spent calculating along the edges of the curve

// Complex number handling
long double z_magnitude(Complex z);

// Generalized site handling
Site* build_site(unsigned int x, unsigned int y);
void print_site(Site* site);
void destroy_site(Site* site);

// Z-Plane Handling
Site* build_zplane();
void print_zplane(Site** zplane);
void destroy_zplane(Site** zplane);

// Mandelbrot API's
long double scale_x(unsigned int pix_x);
long double scale_y(unsigned int pix_y);
int mandelbrot(Site* pixel);

#endif
