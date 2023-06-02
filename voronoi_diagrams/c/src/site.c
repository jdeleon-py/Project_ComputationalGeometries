// VORONOI PIXEL (SITE) SOURCE FILE

#include "site.h"

Pixel* build_pixel(unsigned int x, unsigned int y)
{
	Pixel* new_pixel = NULL;
	new_pixel = (Pixel*)malloc(sizeof(Pixel));
	
	if(new_pixel == NULL)
	{
		printf("Error allocating a pixel!\n");
		return NULL;
	}
	new_pixel -> x = x;
	new_pixel -> y = y;
	return new_pixel;
}
	

Site* build_site(unsigned int x, unsigned int y, bool vor_node)
{
	Site* new_site = NULL;
	new_site = (Site*)malloc(sizeof(Site));

	if(new_site == NULL)
	{
		printf("Error allocating a site!\n");
		return NULL;
	}

	new_site -> pixel = build_pixel(x, y);
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

void print_pixel(Pixel* pixel)
{
	printf("Pixel === (%d, %d)", pixel -> x, pixel -> y);
}

void print_site(Site* site)
{
	printf("Site -> (%d, %d) -> &(%p)\n", site -> pixel -> x, site -> pixel -> y, site);
	printf("Type: \n");
	if(site -> vor_node == true)
	{
		printf("--- Voronoi Node ---\n");
		printf("--- Color: (%d, %d, %d)\n", site -> color.R, site -> color.G, site -> color.B);
	}
	else
	{
		printf("--- QT (Corner) Node ---\n");
		printf("--- Closest Voronoi Site: &(%p) with min dist: %f\n", site -> closest_site, site -> min_distance);
	}
	printf("\n");
}

void destroy_pixel(Pixel* pixel)
{
	free(pixel);
}

void destroy_site(Site* site)
{
	destroy_pixel(site -> pixel);
	free(site);
}

double get_distance(Site* corner, Site* vor_site)
{
	if(corner == NULL || vor_site == NULL) return 0;

	int dx = abs(corner -> pixel -> x - vor_site -> pixel -> x);
	int dy = abs(corner -> pixel -> y - vor_site -> pixel -> y);
	double dist = sqrt((dx * dx) + (dy * dy));
	return dist;
}

// returns true if both sites are in the same location
bool site_check(Site* s1, Site* s2)
{
	if(s1 == NULL || s2 == NULL) return false;

	bool cond_x, cond_y;
	cond_x = s1 -> pixel -> x == s2 -> pixel -> x;
	cond_y = s1 -> pixel -> y == s2 -> pixel -> y;
	return (cond_x && cond_y) ? true : false;
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
