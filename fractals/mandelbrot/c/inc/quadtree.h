// QUADTREE HEADER FILE
// - JAMES DELEON

#ifndef __QUADTREE_H__
#define __QUADTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "mandelbrot.h"
#include "color.h"

#define NODE_CAPACITY 5

typedef struct Sector
{
	Site* center;
	unsigned int radius;

	Color* avg_color;
	Color* std_color;

	Site** zplane;
} Sector;

typedef struct QuadTree
{
	bool divided;
	bool converges;
	Sector* boundary;

	struct QuadTree* nw;
	struct QuadTree* ne;
	struct QuadTree* sw;
	struct QuadTree* se;
} QuadTree;


// SECTOR APIS
Sector* build_sector(Site* center, unsigned int radius);
bool contains_point(Sector* sector, Site* pixel);
void print_sector(Sector* sector);
void destroy_sector(Sector* sector);

// QUADTREE APIS
QuadTree* build_quadtree(Sector* boundary);

int query_points(QuadTree* qtree);
void insert(QuadTree* qtree, Site* pixel);
void subdivide(QuadTree* qtree);
void query_quadtree(QuadTree* qtree, int level);

void print_quadtree(QuadTree* qtree);
void destroy_quadtree(QuadTree* qtree);

// UTILITIES
Color get_avg_color(Sector* sector, Site* site);
Color get_std_color(Sector* sector);

#endif

