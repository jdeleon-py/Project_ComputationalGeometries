// VORONOI PIXEL (SITE) HEADER FILE
// - JAMES DELEON

#ifndef __SITE_H__
#define __SITE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// "external" C library (included in makefile with -lm flag)
#include <math.h>

#define VOR_NUM      500
#define MAX_DISTANCE 10000

// pixel
typedef struct Pixel
{
	unsigned int x;
	unsigned int y;
} Pixel;

// color
typedef struct Color
{
	unsigned int R;
	unsigned int G;
	unsigned int B;
} Color;

// pixels can be identified as:
// - a voronoi node (center pixels of voronoi polygons)
// - a QT Node corner pixel
//
// Sites will be the defining node of the QT data structure
// A QT sector will consist of 4 site pixels (corners)
typedef struct Site
{
	bool vor_node;

	Pixel* pixel;
	Color color;
	
	double min_distance;
	struct Site* closest_site;
} Site;

// Site Handling API's
Site* build_site(unsigned int x, unsigned int y, bool vor_node);
bool site_check(Site* s1, Site* s2);
void print_pixel(Pixel* pixel);
void print_site(Site* site);
void destroy_site(Site* site);

// TODO
/*
 idea for voronoi digram interactions
 
 - color gradient based on site coordinates
 - click to adjust qt and voronoi diagram in real time
*/


// Utilities
Pixel* build_pixel();
double get_distance(Site* corner, Site* vor_site);
Color generate_color();
void destroy_pixel(Pixel* pixel);

#endif
