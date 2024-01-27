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

// Note: functional descriptors are found in associated source files

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

size_t get_site_size(Site* site);
size_t get_sector_size(Sector* sector);
size_t get_qtree_size(QuadTree* qtree);

// query_pixel -> traverses qtree given a pixel location, returns sector info (color)
// is_leaf_node -> given a pixel location, return true if pixel is in leaf node
// query_depth -> given a qtree, return depth of quadtree

#endif

/* END FILE */