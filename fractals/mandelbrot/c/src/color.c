// COLOR HANDLING SOURCE FILE
// - JAMES DELEON

#include "color.h"
#include "mandelbrot.h"

/* MAGMA COLOR MAP */
const Color map_magma[1] = {{0,0,0}};

const Color map_inferno[MAX_COLORS] = 
{
	{0, 0, 0}, {1, 0, 5}, {1, 1, 6}, {1, 1, 8}, {2, 1, 9}, {2, 2, 11}, {2, 3, 12}, {3, 3, 14},
	{4, 4, 16}, {4, 5, 18}, {5, 6, 20}, {6, 6, 22}, {7, 7, 24}, {8, 8, 26}, {9, 9, 28}, {10, 10, 31},
	{11, 11, 33}, {12, 12, 35}, {13, 13, 37}, {14, 14, 39}, {16, 15, 42}, {17, 16, 44}, {18, 17, 46},
	{19, 18, 48}, {20, 19, 51}, {21, 20, 53}, {22, 21, 55}, {24, 22, 57}, {25, 23, 60}, {26, 24, 62},
	{28, 25, 64}, {29, 26, 66}, {30, 27, 68}, {32, 28, 71}, {33, 29, 73}, {35, 30, 75}, {36, 31, 77},
	{38, 32, 79}, {39, 33, 81}, {41, 33, 83}, {42, 34, 85}, {44, 35, 87}, {45, 36, 89}, {47, 37, 91},
	{49, 37, 92}, {50, 38, 94}, {52, 39, 96}, {54, 39, 97}, {55, 40, 99}, {57, 41, 100}, {59, 41, 102},
	{60, 42, 103}, {62, 42, 105}, {64, 43, 106}, {66, 43, 107}, {67, 44, 109}, {69, 44, 110}, {71, 45, 111},
	{72, 45, 112}, {74, 46, 113}, {76, 46, 114}, {77, 47, 115}, {79, 47, 116}, {81, 47, 116}
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