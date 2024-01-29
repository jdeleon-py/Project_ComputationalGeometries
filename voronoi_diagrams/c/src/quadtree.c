// QUADTREE SOURCE FILE
// - JAMES DELEON

#include "quadtree.h"

// SECTOR API SRC

/*
 * - allocation of a sector object
 * - given a structure of a quadtree, a sector defines 1/4 of the tree's current node
 * - for each allocated sector, four corner site objects are also allocated
 *
 * - parameters:
 * 		- pixel with coordinates marking the center of the sector
 * 		- unisigned value defining the radius of the square sector (from center to middle side length)
 * - returns a new sector object
*/
Sector* build_sector(Pixel* center, unsigned int radius)
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

	// each sector has four corner pixels, each of which are allocated as corner sites
	new_sector -> corners[NW] = build_site(center -> x - radius - 0, center -> y - radius - 0, false); // nw
	new_sector -> corners[NE] = build_site(center -> x + radius - 1, center -> y - radius - 0, false); // ne
	new_sector -> corners[SW] = build_site(center -> x - radius - 0, center -> y + radius - 1, false); // sw
	new_sector -> corners[SE] = build_site(center -> x + radius - 1, center -> y + radius - 1, false); // se
	return new_sector;
}

/*
 * - the given sector's corner sites will assign a closest voronoi site from the given array of vor sites
 * - each corner site may be updated with closest vor site and distance
 * - each corner site will be assigned the vor site's color, if it is within minimal range
 *
 * - Time Complexity: O(4k), where k is the number of voronoi sites 
 *
 * - parameters:
 * 		- sector object (for scanning each of the four corner sites)
 * 		- array of voronoi sites
 * - returns (void) - updates sector accordingly
*/
void corner_scan(Sector* sector, Site* vor_sites[])
{
	if(sector == NULL || vor_sites == NULL)
	{
		printf("Error -- cannot find sector or vor sites.\n");
		return;
	}

	double nw_dist, ne_dist, sw_dist, se_dist;
	for(int i = 0; i < VOR_NUM; i++)
	{
		nw_dist = get_distance(sector -> corners[NW], vor_sites[i]);
		ne_dist = get_distance(sector -> corners[NE], vor_sites[i]);
		sw_dist = get_distance(sector -> corners[SW], vor_sites[i]);
		se_dist = get_distance(sector -> corners[SE], vor_sites[i]);

		if(nw_dist < sector -> corners[NW] -> min_distance)
		{
			sector -> corners[NW] -> closest_site = vor_sites[i];
			sector -> corners[NW] -> min_distance = nw_dist;
			sector -> corners[NW] -> color = vor_sites[i] -> color;
		}
		if(ne_dist < sector -> corners[NE] -> min_distance)
		{
			sector -> corners[NE] -> closest_site = vor_sites[i];
			sector -> corners[NE] -> min_distance = ne_dist;
			sector -> corners[NE] -> color = vor_sites[i] -> color;
		}
		if(sw_dist < sector -> corners[SW] -> min_distance)
		{
			sector -> corners[SW] -> closest_site = vor_sites[i];
			sector -> corners[SW] -> min_distance = sw_dist;
			sector -> corners[SW] -> color = vor_sites[i] -> color;
		}
		if(se_dist < sector -> corners[SE] -> min_distance)
		{
			sector -> corners[SE] -> closest_site = vor_sites[i];
			sector -> corners[SE] -> min_distance = se_dist;
			sector -> corners[SE] -> color = vor_sites[i] -> color;
		}
	}		
}

/*
 * - essential function for Voronoi diagram generation
 * - checks each corner site of a sector for similar nearest voronoi sites
 *
 * - returns true if each corner site of a sector has the same closest voronoi site
*/
bool corner_check(Sector* sector)
{
	if(sector == NULL)
	{
		printf("Error -- cannot find sector.\n");
		return false;
	}

	Site* nw_closest = sector -> corners[NW] -> closest_site;
	Site* ne_closest = sector -> corners[NE] -> closest_site;
	Site* sw_closest = sector -> corners[SW] -> closest_site;
	Site* se_closest = sector -> corners[SE] -> closest_site;

	return site_check(nw_closest, ne_closest) && 
			site_check(ne_closest, sw_closest) && 
			site_check(sw_closest, se_closest);
}

/*
 * - prints information about the given sector object
 * - prints center, radius, and info on each corner site
*/
void print_sector(Sector* sector)
{
	if(sector == NULL)
	{
		printf("Error -- cannot find sector.\n");
		return;
	}

	printf("Center: ");
	print_pixel(sector -> center);
	printf(" === Radius: %d\n", sector -> radius);

	print_site(sector -> corners[NW]);
	print_site(sector -> corners[NE]);
	print_site(sector -> corners[SW]);
	print_site(sector -> corners[SE]);
}

/*
 * - deallocates the sector object, along with each corresponding corner site object
*/
void destroy_sector(Sector* sector)
{
	if(sector == NULL)
	{
		printf("Error -- cannot find sector.\n");
		return;
	}

	for(int i = 0; i < 4; i++)
	{
		destroy_site(sector -> corners[i]);
	}
	free(sector);
}

// QUADTREE API SRC

/*
 *
*/
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

	new_qtree -> nw = NULL;
	new_qtree -> ne = NULL;
	new_qtree -> sw = NULL;
	new_qtree -> se = NULL;
	return new_qtree;
}

/*
 * -
*/
void subdivide(QuadTree* qtree)
{
	unsigned int centerx, centery, rad;

	centerx = qtree -> boundary -> center -> x;
	centery = qtree -> boundary -> center -> y;
	rad = qtree -> boundary -> radius;

	Pixel* nw_center = build_pixel(centerx - (rad / 2), centery - (rad / 2));
	Pixel* ne_center = build_pixel(centerx + (rad / 2), centery - (rad / 2));
	Pixel* sw_center = build_pixel(centerx - (rad / 2), centery + (rad / 2));
	Pixel* se_center = build_pixel(centerx + (rad / 2), centery + (rad / 2));

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

/*
 * -
*/
size_t get_site_size(Site* site)
{
	if(site == NULL) return 0;

	size_t size_bytes = sizeof(*site);
	return size_bytes;
}

/*
 * -
*/
size_t get_sector_size(Sector* sector)
{
	if(sector == NULL) return 0;

	size_t size_bytes = sizeof(*sector);
	return size_bytes;
}

/*
 * - 
*/
size_t get_qtree_size(QuadTree* qtree)
{
	if(qtree == NULL) return 0;

	size_t size_bytes = sizeof(*qtree);
	size_bytes += get_qtree_size(qtree -> nw);
	size_bytes += get_qtree_size(qtree -> ne);
	size_bytes += get_qtree_size(qtree -> sw);
	size_bytes += get_qtree_size(qtree -> se);
	return size_bytes;
}

void print_quadtree(QuadTree* qtree)
{
	if(qtree == NULL)
	{
		printf("Error -- cannot find quadtree.\n");
		return;
	}

	print_sector(qtree -> boundary);

	print_quadtree(qtree -> nw);
	print_quadtree(qtree -> ne);
	print_quadtree(qtree -> sw);
	print_quadtree(qtree -> se);
}

void destroy_quadtree(QuadTree* qtree)
{
	if(qtree == NULL) 
	{
		printf("Error -- cannot find quadtree.\n");
		return;
	}

	destroy_sector(qtree -> boundary);
	// TODO: destroy vor_sites

	destroy_quadtree(qtree -> nw);
	destroy_quadtree(qtree -> ne);
	destroy_quadtree(qtree -> sw);
	destroy_quadtree(qtree -> se);

	free(qtree);	
}

/* END FILE */