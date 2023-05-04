// POINT (SITE) HEADER FILE
// - JAMES DELEON

#ifndef __POINT_H__
#define __POINT_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct Point
{
	unsigned int x;
	unsigned int y;
} Point;

Point* build_point(unsigned int x, unsigned int y);

void print_point(Point* point);
void destroy_point(Point* point);

#endif

