// COLOR HANDLING SOURCE FILE
// - JAMES DELEON

#include "color.h"
#include "mandelbrot.h"

/* MAGMA COLOR MAP */
const Color map_magma[1] = {{0,0,0}};

const Color map_inferno[MAX_COLORS] =
{
	{0, 0, 0},          // Black
	{12, 3, 49},        // Dark purple
	{26, 8, 84},
	{40, 13, 115},
	{55, 18, 142},
	{70, 23, 167},
	{85, 28, 190},
	{100, 34, 210},
	{111, 39, 222},
	{127, 48, 238},     // Blue
	{138, 55, 247},
	{150, 64, 255},     // Teal-blue
	{163, 73, 255},
	{177, 84, 255},
	{192, 98, 252},     // Teal
	{207, 113, 243},
	{223, 130, 233},    // Yellow-green
	{240, 150, 220},
	{253, 173, 204},    // Orange
	{255, 198, 185},
	{255, 212, 175},
	{255, 227, 164},    // Bright orange-yellow
	{255, 255, 142}
};


/* VIRIDIS COLOR MAP */
const Color map_viridis[1] = {{0, 0, 0}};

/*
 * allocation function for a color structure
*/
Color* build_color()
{
	Color* new_color = NULL;
	new_color = (Color*)malloc(sizeof(Color));

	if(new_color == NULL)
	{
		printf("Error allocating color!\n");
		return NULL;
	}
	new_color -> R = 0;
	new_color -> G = 0;
	new_color -> B = 0;
	return new_color;	
}

/*
 * this function maps a color to a pixel based on the number of 
 * convergence iterations needed
 * uses modulo arithmetic to wrap around the defined color map
*/
Color map_color_pixel(const Color map[], int iters)
{
	int map_index;

	map_index = iters % MAX_COLORS;
	return map[map_index];
}

/*
 * prints the RGB components of the color object
*/
void print_color(Color color)
{
	printf("(%d, %d, %d)\n", color.R, color.G, color.B);
}

/*
 * deallocation for a color structure
*/
void destroy_color(Color* color)
{
	if(color == NULL)
	{
		printf("Warning... cannot deallocate null ptr.\n");
		return;
	}
	free(color);
}

/* END FILE */