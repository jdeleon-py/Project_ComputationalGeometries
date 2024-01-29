// VORONOI PIXEL (SITE) SOURCE FILE

#include "site.h"

/*
 * - allocates a pixel object
 *
 * - parameters: x and y coordinates, where 0 <= x,y <= WINDOW DIM
 * - returns: pixel object
*/
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

/*
 * - allocates a voronoi/QT site object
 * - pixels can be identified as:
 * 		- a voronoi node (center pixels of voronoi polygons)
 * 		- a QT Node corner pixel
 *
 * Sites will be the defining node of the QT data structure
 * A QT sector will consist of 4 site pixels (corners)
 *
 * parameters: 
 * 		- x and y coordinates, where x,y are unsigned
 *		- boolean detecting a voronoi node, else it is a QT corner pixel
 * returns: site object
*/
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
		// assigns a random color that all "near" corner sites will copy
		new_site -> color = generate_color();
	}
	else // is a QT corner
	{
		// is a QT corner with a closest distance voronoi site
		new_site -> min_distance = MAX_DISTANCE;
		new_site -> closest_site = NULL;
	}
	return new_site; 
}

/*
 * - prints content of pixel object: 
 * 		- coordinates
*/
void print_pixel(Pixel* pixel)
{
	printf("Pixel === (%d, %d)", pixel -> x, pixel -> y);
}

/*
 * - prints content of site object:
 *		- coordinates
 *		- type of node (QT corner or Voronoi site)
 *		- if node is a voronoi node, print color
 *		- if node is a QT corner, print closest site address with distance to that site
*/
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

/*
 * - deallocates pixel object
*/
void destroy_pixel(Pixel* pixel)
{
	free(pixel);
}

/*
 * - deallocates site object
 * - intermediately deallocates pixel object
*/
void destroy_site(Site* site)
{
	destroy_pixel(site -> pixel);
	free(site);
}

/*
 * - calculates the euclidean distance between QT corner site and a voronoi site
 * - parameters:
 *		- confirmed QT corner site pixel
 *		- confirmed voronoi site pixel
 * - returns:
 *		- euclidean distance as a double precision float value
*/
double get_distance(Site* corner, Site* vor_site)
{
	if(corner == NULL || vor_site == NULL) return 0;

	int dx = abs(corner -> pixel -> x - vor_site -> pixel -> x);
	int dy = abs(corner -> pixel -> y - vor_site -> pixel -> y);
	double dist = sqrt((dx * dx) + (dy * dy));
	return dist;
}

/*
 * - boolean check between coordinates of two sites
 *
 * - parameters:
 *		- sites 1 and 2
 * - returns true if sites 1 and 2 are in the same location
*/
bool site_check(Site* s1, Site* s2)
{
	if(s1 == NULL || s2 == NULL) return false;

	bool cond_x, cond_y;
	cond_x = s1 -> pixel -> x == s2 -> pixel -> x;
	cond_y = s1 -> pixel -> y == s2 -> pixel -> y;
	return (cond_x && cond_y) ? true : false;
}

/*
 * - assigns a RGB color at random
 *
 * - returns a color object, where attributes R,G,B have a random assignment between 0 and 255
 * - TODO: add/identify seed to random number generator
*/
Color generate_color()
{
	Color new_color;
	unsigned int lower = 0, upper = 255;

	new_color.R = (rand() % (upper - lower + 1)) + lower;
	new_color.G = (rand() % (upper - lower + 1)) + lower;
	new_color.B = (rand() % (upper - lower + 1)) + lower;
	return new_color;
}

/* END FILE */