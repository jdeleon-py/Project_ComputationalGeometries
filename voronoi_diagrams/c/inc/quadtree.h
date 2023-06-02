// QUADTREE HEADER FILE
// - JAMES DELEON

#ifndef __QUADTREE_H__
#define __QUADTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "site.h"

enum Corner {NW, NE, SW, SE};

typedef struct Sector
{
	Pixel* center;
	unsigned int radius;
	Site* corners[4];
} Sector;

typedef struct QuadTree
{
	bool divided;
	Sector* boundary;

	struct QuadTree* nw;
	struct QuadTree* ne;
	struct QuadTree* sw;
	struct QuadTree* se;
} QuadTree;

// SECTOR API PROTOTYPES
Sector* build_sector(Pixel* center, unsigned int radius);
bool corner_check(Sector* sector);
void corner_scan(Sector* sector, Site* vor_sites[]);
void print_sector(Sector* sector);
void destroy_sector(Sector* sector);

// QUADTREE API PROTOTYPES
QuadTree* build_quadtree(Sector* boundary);
void subdivide(QuadTree* qtree);
void print_quadtree(QuadTree* qtree);
void destroy_quadtree(QuadTree* qtree);

#endif
