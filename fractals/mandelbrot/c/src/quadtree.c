// QUADTREE SOURCE FILE
// - JAMES DELEON

#include "quadtree.h"

// SECTOR API SRC
Sector* build_sector(Site* center, unsigned int radius)
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
	new_sector -> avg_color = build_color();
	new_sector -> std_color = build_color();
	//new_sector -> zplane = build_zplane();
	new_sector -> corners = get_corners(new_sector -> zplane, center, radius);
	return new_sector;	
}

Site* get_corners(Site* zplane, Site* center, unsigned int radius)
{
	Site* new_corners[4]; // [nw, ne, sw, se]

	new_corners[0] = build_site(center -> x - radius - 0, center -> y - radius - 0);
	new_corners[1] = build_site(center -> x + radius - 1, center -> y - radius - 0);
	new_corners[2] = build_site(center -> x - radius - 0, center -> y + radius - 1);
	new_corners[3] = build_site(center -> x + radius - 1, center -> y + radius - 1);
	return new_corners; 
}

bool contains_point(Sector* sector, Site* pixel)
{
	bool x_min_cond, x_max_cond, y_min_cond, y_max_cond;

	x_min_cond = (pixel -> x >=((sector -> center -> x) - sector -> radius));
	x_max_cond = (pixel -> x < ((sector -> center -> x) + sector -> radius));
	y_min_cond = (pixel -> y >=((sector -> center -> y) - sector -> radius));
	y_max_cond = (pixel -> y < ((sector -> center -> y) + sector -> radius));
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
	destroy_site(sector -> center);
	destroy_zplane(sector -> zplane);
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
	new_qtree -> converges = false;
	new_qtree -> boundary = boundary;

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
		printf("QTree at maximum resolution and capacity. ");
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
	else
	{
		printf("Unexpected error!\n");
		return;
	}
}

void subdivide(QuadTree* qtree)
{
	unsigned int centerx, centery, rad;

	centerx = qtree -> boundary -> center -> x;
	centery = qtree -> boundary -> center -> y;
	rad = qtree -> boundary -> radius;

	Point* nw_center = build_site(centerx - (rad / 2), centery - (rad / 2));
	Point* ne_center = build_site(centerx + (rad / 2), centery - (rad / 2));
	Point* sw_center = build_site(centerx - (rad / 2), centery + (rad / 2));
	Point* se_center = build_site(centerx + (rad / 2), centery + (rad / 2));

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

// COLOR HANDLING UTILITIES
Color get_avg_color(Sector* sector, Site* site);
Color get_std_color(Sector* sector);

// FILE HANDLING UTILITIES
void load_quadtree(char* filename) {}

void save_quadtree(char* filename) {}
void save_iters(char* filename) {}
void save_colors(char* filename) {}


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

// function to request the number of mandelbrot escape iterations 
// associated with the selected pixel
void query_iters(QuadTree* qtree) {}

// function to request the color of the selected pixel
void query_color(QuadTree* qtree)
{
	return qtree -> boundary -> center -> color;
}

// returns info on root node of qtree
void query_node_root(QuadTree* qtree) {}

// returns info on all leaf nodes of qtree
void query_node_leaf(QuadTree* qtree)
{
	if(qtree == NULL) return;

	query_node_leaf(qtree -> nw);
	query_node_leaf(qtree -> ne);
	query_node_leaf(qtree -> sw);
	query_node_leaf(qtree -> se);
	
	if(qtree -> boundary -> radius == 1)
	{
		printf("Leaf node found...\n");
		printf("=== Boundary - Center: (#, #), Radius: #\n");
		printf("=== to be continued...\n");
		printf("\n");
	}
}

// given a depth level, returns info on all qtrees in specified level
void query_node_n(QuadTree* qtree, int level) {}

// function to determine the depth level of the selected pixel
void query_depth {}















