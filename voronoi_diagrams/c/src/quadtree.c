// QUADTREE SOURCE FILE
// - JAMES DELEON

#include "quadtree.h"

// SECTOR API SRC
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
	new_sector -> corners[NW] = build_site(center -> x - radius - 0, center -> y - radius - 0, false); // nw
	new_sector -> corners[NE] = build_site(center -> x + radius - 1, center -> y - radius - 0, false); // ne
	new_sector -> corners[SW] = build_site(center -> x - radius - 0, center -> y + radius - 1, false); // sw
	new_sector -> corners[SE] = build_site(center -> x + radius - 1, center -> y + radius - 1, false); // se
	return new_sector;
}

void corner_scan(Sector* sector, Site* vor_sites[])
{
	if(sector == NULL || vor_sites == NULL) return;
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
		}
		if(ne_dist < sector -> corners[NE] -> min_distance)
		{
			sector -> corners[NE] -> closest_site = vor_sites[i];
			sector -> corners[NE] -> min_distance = ne_dist;
		}
		if(sw_dist < sector -> corners[SW] -> min_distance)
		{
			sector -> corners[SW] -> closest_site = vor_sites[i];
			sector -> corners[SW] -> min_distance = sw_dist;
		}
		if(se_dist < sector -> corners[SE] -> min_distance)
		{
			sector -> corners[SE] -> closest_site = vor_sites[i];
			sector -> corners[SE] -> min_distance = se_dist;
		}
	}		
}

bool corner_check(Sector* sector)
{
	if(sector == NULL) return false;

	Site* nw_closest = sector -> corners[NW] -> closest_site;
	Site* ne_closest = sector -> corners[NE] -> closest_site;
	Site* sw_closest = sector -> corners[SW] -> closest_site;
	Site* se_closest = sector -> corners[SE] -> closest_site;

	return site_check(nw_closest, ne_closest) && 
			site_check(ne_closest, sw_closest) && 
			site_check(sw_closest, se_closest);
}

void print_sector(Sector* sector)
{
	printf("Center: ");
	print_pixel(sector -> center);
	printf(" === Radius: %d\n", sector -> radius);

	print_site(sector -> corners[NW]);
	print_site(sector -> corners[NE]);
	print_site(sector -> corners[SW]);
	print_site(sector -> corners[SE]);
}

void destroy_sector(Sector* sector)
{
	if(sector == NULL) {return;}

	for(int i = 0; i < 4; i++)
	{
		destroy_site(sector -> corners[i]);
	}
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

	new_qtree -> nw = NULL;
	new_qtree -> ne = NULL;
	new_qtree -> sw = NULL;
	new_qtree -> se = NULL;
	return new_qtree;
}

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

void print_quadtree(QuadTree* qtree)
{
	if(qtree == NULL) return;

	print_sector(qtree -> boundary);

	print_quadtree(qtree -> nw);
	print_quadtree(qtree -> ne);
	print_quadtree(qtree -> sw);
	print_quadtree(qtree -> se);
}

void destroy_quadtree(QuadTree* qtree)
{
	if(qtree == NULL) {return;}

	destroy_sector(qtree -> boundary);
	// TODO: destroy vor_sites

	destroy_quadtree(qtree -> nw);
	destroy_quadtree(qtree -> ne);
	destroy_quadtree(qtree -> sw);
	destroy_quadtree(qtree -> se);

	free(qtree);	
}
