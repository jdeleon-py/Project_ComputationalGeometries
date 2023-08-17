// QUADTREE HEADER FILE
// - JAMES DELEON

#ifndef __QUADTREE_H__
#define __QUADTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "point.h"
//#include "pixel.h"

#define NODE_CAPACITY 5

typedef struct Site
{
	unsigned int x;
	unsigned int y;
	bool gridlocked; // determines whether to treat this site as an independent particle?
} Site;

typedef struct Sector
{
	Site* center;
	unsigned int radius;
	Site* corners[4];
} Sector;

typedef struct QuadTree
{
	bool divided;
	Site* particles[NODE_CAPACITY];
	Sector* boundary;

	struct QuadTree* nw;
	struct QuadTree* ne;
	struct QuadTree* sw;
	struct QuadTree* se;
} QuadTree;

// SITE API PROTOTYPES
Site* build_site(unsigned int x, unsigned int y, bool grid);
void print_site(Site* pixel);
void destroy_site(Site* pixel);

// SECTOR API PROTOTYPES
Sector* build_sector(Site* center, unsigned int radius);
bool contains_point(Sector* sector, Site* point);
void print_sector(Sector* sector);
void destroy_sector(Sector* sector);

// QUADTREE API PROTOTYPES
QuadTree* build_quadtree(Sector* boundary);
int query_points(QuadTree* qtree);
void insert(QuadTree* qtree, Point* point);
void subdivide(QuadTree* qtree);
void print_quadtree(QuadTree* qtree);
void destroy_quadtree(QuadTree* qtree);

#endif

