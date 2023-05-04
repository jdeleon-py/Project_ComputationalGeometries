// QUADTREE SOURCE FILE
// - JAMES DELEON

#include "quadtree.h"

// SECTOR API SRC
Sector* build_sector(Point* center, unsigned int radius)
{
	Sector* new_sector = NULL;

	new_sector = (Sector*)malloc(sizeof(Sector));
	new_sector -> center = center;
	new_sector -> radius = radius;
	return new_sector;	
}

bool contains_point(Sector* sector, Point* point)
{
	bool x_min_cond, x_max_cond, y_min_cond, y_max_cond;

	x_min_cond = (point -> x < ((sector -> center -> x) + sector -> radius);
	x_max_cond = (point -> x > ((sector -> center -> x) - sector -> radius);
	y_min_cond = (point -> y < ((sector -> center -> y) + sector -> radius);
	y_max_cond = (point -> y > ((sector -> center -> y) - sector -> radius);
	return (x_min_cond && y_min_cond && x_max_cond && y_max_cond);
}

/*
bool contains_point(Sector sector, Point point)
{
	bool x_min_cond, x_max_cond, y_min_cond, y_max_cond;

	x_min_cond = (point.x < ((sector -> center.x) + sector.radius);
	x_max_cond = (point.x > ((sector -> center.x) - sector.radius);
	y_min_cond = (point.y < ((sector -> center.y) + sector.radius);
	y_max_cond = (point.y > ((sector -> center.y) - sector.radius);
	return (x_min_cond && y_min_cond && x_max_cond && y_max_cond);
}
*/

void print_sector(Sector* sector);

void destroy_sector(Sector* sector)
{
	destroy_point(sector -> center);
	free(sector);
}


// QUADTREE API SRC
QuadTree* build_quadtree(Sector* boundary)
{
	QuadTree* new_qtree = NULL;

	new_qtree = (QuadTree*)malloc(sizeof(QuadTree));
	new_qtree -> divided = false;
	new_qtree -> points = NULL; // ?
	new_qtree -> boundary = boundary;

	new_qtree -> nw = NULL;
	new_qtree -> ne = NULL;
	new_qtree -> sw = NULL;
	new_qtree -> se = NULL;
	return new_qtree;
}

void insert(QuadTree* qtree, Point* point)
{
	if(contains_point(qtree -> boundary, point) == false) {return;}

	int point_count = query_points(qtree -> points);
	if(point_count < NODE_CAPACITY)
	{
		qtree -> points[point_count] = point;
		return;
	}
	else if(qtree -> divided == false) {subdivide(qtree);}

	if     (contains_point(qtree -> nw -> boundary, point) == true) {insert(qtree -> nw, point);}
	else if(contains_point(qtree -> ne -> boundary, point) == true) {insert(qtree -> ne, point);}
	else if(contains_point(qtree -> sw -> boundary, point) == true) {insert(qtree -> sw, point);}
	else if(contains_point(qtree -> se -> boundary, point) == true) {insert(qtree -> se, point);}
	return;
}

// function to count how many points exist in a qtree
int query_points(Point* arr[])
{
	int count = 0;

	for(int i = 0; i < NODE_CAPACITY; i++)
	{
		if(arr[i] != NULL)
		{
			count++;
		}
	}
	return count;
}

void subdivide(QuadTree* qtree)
{
	unsigned int centerx, centery, rad;

	centerx = qtree -> boundary -> center -> x;
	centery = qtree -> boundary -> center -> y;
	rad = qtree -> boundary -> radius;

	if(rad == 1) {return;}
	else
	{
		Point* nw_center = build_point(centerx - (rad / 2), centery - (rad / 2));
		Point* ne_center = build_point(centerx + (rad / 2), centery - (rad / 2));
		Point* sw_center = build_point(centerx - (rad / 2), centery + (rad / 2));
		Point* se_center = build_point(centerx + (rad / 2), centery + (rad / 2));
		qtree -> divided = true;
		return;
	}
}

void print_qtree(QuadTree* qtree) {}

void destroy_quadtree(QuadTree* qtree)
{
	if(qtree != NULL)
	{
		destroy_sector(qtree -> boundary);
		for(int i = 0; i < NODE_CAPACITY; i++)
		{
			destroy_point(qtree -> points[i]);
		}
		free(points);

		destroy_quadtree(qtree -> nw);
		destroy_quadtree(qtree -> ne);
		destroy_quadtree(qtree -> sw);
		destroy_quadtree(qtree -> se);
	}
	free(qtree);	
}
