// VORONOI PIXEL (SITE) SOURCE FILE

#include "site.h"

Site* build_site(unsigned int x, unsigned int y, bool vor_node)
{
	Site* new_site = NULL;
	new_site = (Site*)malloc(sizeof(Site));

	if(new_site == NULL)
	{
		printf("Error allocating a site!\n");
		return NULL;
	}

	new_site -> x = x;
	new_site -> y = y;
	new_site -> vor_node = vor_node;

	if(vor_node == true) // is a voronoi site
	{
		new_site -> color = generate_color();
	}
	else // is a QT corner
	{
		new_site -> min_distance = MAX_DISTANCE;
		new_site -> closest_site = NULL;
	}
	return new_site; 
}

void print_site(Site* site)
{
	printf("Site -> (%d, %d) -> &%p\n", site -> x, site -> y, site);
	printf("Type: \n");
	if(site -> vor_node == true)
	{
		printf("--- Voronoi Node ---\n");
		printf("--- Color: (%d, %d, %d)\n", site -> color.R, site -> color.G, site -> color.B);
	}
	else
	{
		printf("--- QT (Corner) Node ---\n");
		printf("--- Closest Voronoi Site: &%p with min dist: %d\n", site -> closest_site, site -> min_distance);
	}
	printf("\n");
}

void destroy_site(Site* site)
{
	free(site);
}

double get_distance(Site* corner, Site* vor_site)
{
	if(corner == NULL || vor_site == NULL) return 0;

	int dx = abs(corner -> x - vor_site -> x);
	int dy = abs(corner -> y - vor_site -> y);
	double dist = sqrt((dx * dx) + (dy * dy));
	return dist;
}

Color generate_color()
{
	Color new_color;
	unsigned int lower = 0, upper = 255;

	new_color.R = (rand() % (upper - lower + 1)) + lower;
	new_color.G = (rand() % (upper - lower + 1)) + lower;
	new_color.B = (rand() % (upper - lower + 1)) + lower;
	return new_color;
}
