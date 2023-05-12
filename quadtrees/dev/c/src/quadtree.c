// QUADTREE SOURCE FILE
// - JAMES DELEON

#include "quadtree.h"

// SECTOR API SRC
Sector* build_sector(Point* center, unsigned int radius)
{
	Sector* new_sector = NULL;
	new_sector = (Sector*)malloc(sizeof(Sector));
	if(new_sector == NULL)
	{
		printf("Error allocating sector!\n");
		return NULL;
	}

	new_sector -> center = center;
	new_sector -> radius = radius;
	return new_sector;	
}

bool contains_point(Sector* sector, Point* point)
{
	bool x_min_cond, x_max_cond, y_min_cond, y_max_cond;

	x_min_cond = (point -> x >=((sector -> center -> x) - sector -> radius));
	x_max_cond = (point -> x < ((sector -> center -> x) + sector -> radius));
	y_min_cond = (point -> y >=((sector -> center -> y) - sector -> radius));
	y_max_cond = (point -> y < ((sector -> center -> y) + sector -> radius));
	return (x_min_cond && y_min_cond && x_max_cond && y_max_cond);
}

void print_sector(Sector* sector)
{
	printf("Center: ");
	print_point(sector -> center);
	printf("Radius: %d\n", sector -> radius);
}

void destroy_sector(Sector* sector)
{
	if(sector == NULL) {return;}
	destroy_point(sector -> center);
	free(sector);
}


// QUADTREE API SRC
QuadTree* build_quadtree(Sector* boundary)
{
	QuadTree* new_qtree = NULL;
	new_qtree = (QuadTree*)malloc(sizeof(QuadTree));
	if(new_qtree == NULL)
	{
		printf("Error allocating quadtree!\n");
		return NULL;
	}

	new_qtree -> divided = false;
	new_qtree -> boundary = boundary;
	for(int i = 0; i < NODE_CAPACITY; i++)
	{
		new_qtree -> points[i] = NULL;
	}

	new_qtree -> nw = NULL;
	new_qtree -> ne = NULL;
	new_qtree -> sw = NULL;
	new_qtree -> se = NULL;
	return new_qtree;
}

void insert(QuadTree* qtree, Point* point)
{
	if(qtree == NULL) {return;}
	if(!contains_point(qtree -> boundary, point)) {return;}
	if(qtree -> boundary -> radius <= 1)
	{
		printf("Cannot add point: ");
		print_point(point);
		destroy_point(point);
		return;
	}

	int point_count = query_points(qtree);
	if(point_count < NODE_CAPACITY)
	{
		qtree -> points[point_count] = point;
		return;
	}
	else if(qtree -> divided == false) {subdivide(qtree);}

	if     (contains_point(qtree -> nw -> boundary, point)) {insert(qtree -> nw, point);}
	else if(contains_point(qtree -> ne -> boundary, point)) {insert(qtree -> ne, point);}
	else if(contains_point(qtree -> sw -> boundary, point)) {insert(qtree -> sw, point);}
	else if(contains_point(qtree -> se -> boundary, point)) {insert(qtree -> se, point);}
}

// function to count how many points exist in a qtree
int query_points(QuadTree* qtree)
{
	int count = 0;

	for(int i = 0; i < NODE_CAPACITY; i++)
	{
		if(qtree -> points[i] != NULL)
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

	if(rad <= 1) {return;}
	Point* nw_center = build_point(centerx - (rad / 2), centery - (rad / 2));
	Point* ne_center = build_point(centerx + (rad / 2), centery - (rad / 2));
	Point* sw_center = build_point(centerx - (rad / 2), centery + (rad / 2));
	Point* se_center = build_point(centerx + (rad / 2), centery + (rad / 2));

	Sector* nw_sector = build_sector(nw_center, rad / 2);
	Sector* ne_sector = build_sector(ne_center, rad / 2);
	Sector* sw_sector = build_sector(sw_center, rad / 2);
	Sector* se_sector = build_sector(se_center, rad / 2);

	qtree -> nw = build_quadtree(nw_sector);
	qtree -> ne = build_quadtree(ne_sector);
	qtree -> sw = build_quadtree(sw_sector);
	qtree -> se = build_quadtree(se_sector);
	qtree -> divided = true;
}

void print_quadtree(QuadTree* qtree)
{
	if(qtree != NULL)
	{
		print_sector(qtree -> boundary);
		for(int i = 0; i < NODE_CAPACITY; i++)
		{
			if(qtree -> points[i] != NULL)
			{
				print_point(qtree -> points[i]);
			}
		}
		print_quadtree(qtree -> nw);
		print_quadtree(qtree -> ne);
		print_quadtree(qtree -> sw);
		print_quadtree(qtree -> se);
	}
}

void destroy_quadtree(QuadTree* qtree)
{
	if(qtree == NULL) {return;}

	destroy_sector(qtree -> boundary);
	for(int i = 0; i < NODE_CAPACITY; i++)
	{
		if(qtree -> points[i] != NULL)
		{
			destroy_point(qtree -> points[i]);
		}
	}

	destroy_quadtree(qtree -> nw);
	destroy_quadtree(qtree -> ne);
	destroy_quadtree(qtree -> sw);
	destroy_quadtree(qtree -> se);

	free(qtree);	
}
