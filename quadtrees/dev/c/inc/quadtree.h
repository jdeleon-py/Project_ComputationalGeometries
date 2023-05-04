// QUADTREE HEADER FILE
// - JAMES DELEON

#ifndef __QUADTREE_H__
#define __QUADTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "point.h"

#define NODE_CAPACITY 4

typedef struct Sector
{
	Point* center;
	unsigned int radius;
};

typedef struct QuadTree
{
	bool divided;
	Point** points;
	Sector* boundary;

	QuadTree* nw;
	QuadTree* ne;
	QuadTree* sw;
	QuadTree* se;
};


// SECTOR API PROTO
Sector* build_sector(Point* center, unsigned int radius);
bool contains_point(Sector* sector, Point* point);
void print_sector(Sector* sector);
void destroy_sector(Sector* sector);

// QUADTREE API PROTO
QuadTree* build_quadtree(Sector* boundary);
int query_points(Point* arr[]);
void insert(QuadTree* qtree, Point* point);
void subdivide(QuadTree* qtree);
void print_qtree(QuadTree* qtree);
void destroy_quadtree(QuadTree* qtree);

#endif

