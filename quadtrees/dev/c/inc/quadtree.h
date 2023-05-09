// QUADTREE HEADER FILE
// - JAMES DELEON

#ifndef __QUADTREE_H__
#define __QUADTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "point.h"

#define NODE_CAPACITY 5

typedef struct Sector
{
	Point* center;
	unsigned int radius;
} Sector;

typedef struct QuadTree
{
	bool divided;
	Point* points[NODE_CAPACITY];
	Sector* boundary;

	struct QuadTree* nw;
	struct QuadTree* ne;
	struct QuadTree* sw;
	struct QuadTree* se;
} QuadTree;


// SECTOR API PROTO
Sector* build_sector(Point* center, unsigned int radius);
bool contains_point(Sector* sector, Point* point);
void print_sector(Sector* sector);
void destroy_sector(Sector* sector);

// QUADTREE API PROTO
QuadTree* build_quadtree(Sector* boundary);
int query_points(QuadTree* qtree);
void insert(QuadTree* qtree, Point* point);
void subdivide(QuadTree* qtree);
void print_quadtree(QuadTree* qtree);
void destroy_quadtree(QuadTree* qtree);

#endif

