// POINT (SITE) SOURCE FILE
// - JAMES DELEON

#include "point.h"

Point* build_point(unsigned int x, unsigned int y)
{
	Point* new_point = NULL;

	new_point = (Point*)malloc(sizeof(Point));
	new_point -> x = x;
	new_point -> y = y;
	return new_point;
}

void print_point(Point* point)
{
	printf("(%d, %d)\n", point -> x, point -> y);
}

void destroy_point(Point* point)
{
	free(point);
}

