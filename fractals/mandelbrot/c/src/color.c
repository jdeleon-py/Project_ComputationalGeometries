// COLOR HANDLING SOURCE FILE

#include "color.h"
#include "mandelbrot.h"

const Color map_magma[1] = {{0,0,0}};

const Color map_inferno[MAX_COLORS] =
{
	{0, 0, 0},			// Black
	{6, 1, 25},
	{12, 3, 49},
	{17, 4, 61},		// Dark purple
	{22, 6, 73},
	{26, 8, 84},
	{31, 10, 95},
	{36, 11, 105},
	{40, 13, 115},
	{45, 14, 124},		// Purple
	{50, 16, 133},
	{55, 18, 142},
	{60, 19, 151},
	{65, 21, 159},
	{70, 23, 167},
	{75, 25, 175},
	{80, 26, 182},		// Blue-purple
	{85, 28, 190},
	{90, 30, 197},
	{95, 32, 203},
	{100, 34, 210},
	{105, 37, 216},
	{111, 39, 222},
	{116, 42, 228},
	{121, 45, 233},
	{127, 48, 238},		// Blue
	{132, 52, 243},
	{138, 55, 247},
	{144, 60, 251},
	{150, 64, 255},		// Teal-blue
	{157, 68, 255},
	{163, 73, 255},
	{170, 78, 255},
	{177, 84, 255},
	{184, 91, 255},		// Teal
	{192, 98, 252},
	{199, 105, 248},
	{207, 113, 243},
	{215, 121, 239},
	{223, 130, 233},
	{231, 140, 227},	// Yellow-green
	{240, 150, 220},
	{248, 161, 212},
	{253, 173, 204},	// Orange
	{255, 185, 195},
	{255, 198, 185},
	{255, 212, 175},
	{255, 227, 164},	// Bright orange-yellow
	{255, 242, 153},
	{255, 255, 142}
};

const Color map_viridis[1] = {{0, 0, 0}};

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

Color map_color_pixel(const Color map[], int iters)
{
	int map_index;

	map_index = iters % MAX_COLORS;
	return map[map_index];
}

void print_color(Color color)
{
	printf("(%d, %d, %d)\n", color.R, color.G, color.B);
}

void destroy_color(Color* color)
{
	if(color == NULL)
	{
		printf("Warning... cannot deallocate null ptr.\n");
		return;
	}
	free(color);
}


