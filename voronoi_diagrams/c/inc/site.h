// VORONOI PIXEL (SITE) HEADER FILE

#ifndef __SITE_H__
#define __SITE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_DISTANCE 10000

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

	unsigned int x;
	unsigned int y;
	Color color;
	
	unsigned int min_distance;
	struct Site* closest_site;
} Site;

// Site Handling API's
Site* build_site(unsigned int x, unsigned int y, bool vor_node);
void print_site(Site* site);
void destroy_site(Site* site);

double get_distance(Site* corner, Site* vor_site);
Color generate_color();

#endif
