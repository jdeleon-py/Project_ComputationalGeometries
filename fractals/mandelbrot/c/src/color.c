// COLOR HANDLING SOURCE FILE
// - JAMES DELEON

#include "color.h"
#include "mandelbrot.h"

/* MAGMA COLOR MAP */
const Color map_magma[1] = {{0,0,0}};

const Color map_inferno[MAX_COLORS] = 
{
	{0, 0, 4},
	{2, 1, 10},
	{4, 3, 19},
	{7, 5, 27},
	{11, 7, 36},
	{16, 9, 46},
	{21, 11, 56},
	{27, 12, 65},
	{34, 12, 75},
	{40, 11, 84},
	{48, 10, 91},
	{55, 9, 97},
	{62, 9, 102},
	{69, 10, 105},
	{75, 12, 107},
	{82, 14, 109},
	{88, 16, 110},
	{95, 19, 110},
	{101, 21, 110},
	{108, 24, 110},
	{114, 26, 110},
	{120, 28, 109},
	{127, 30, 108},
	{133, 33, 107},
	{140, 35, 105},
	{146, 37, 104},
	{153, 40, 101},
	{159, 42, 99},
	{165, 45, 96},
	{172, 47, 93},
	{178, 50, 90},
	{184, 53, 87},
	{190, 56, 83},
	{196, 60, 79},
	{201, 64, 75},
	{207, 68, 70},
	{212, 72, 66},
	{217, 77, 61},
	{221, 82, 57},
	{226, 87, 52},
	{230, 93, 47},
	{234, 99, 42},
	{237, 105, 37},
	{240, 111, 32},
	{243, 118, 27},
	{245, 125, 21},
	{247, 132, 16},
	{249, 139, 11},
	{250, 146, 7},
	{251, 154, 6},
	{252, 161, 8},
	{252, 169, 14},
	{252, 177, 21},
	{251, 185, 30},
	{250, 193, 39},
	{249, 201, 49},
	{247, 209, 60},
	{246, 217, 72},
	{244, 224, 85},
	{242, 232, 100},
	{241, 239, 116},
	{243, 245, 133},
	{246, 250, 150},
	{252, 255, 164}
};

/* VIRIDIS COLOR MAP */
const Color map_viridis[MAX_COLORS] = 
{
	{68, 1, 84},
	{70, 7, 90},
	{71, 13, 96},
	{71, 19, 101},
	{72, 24, 107},
	{72, 30, 111},
	{72, 35, 116},
	{72, 40, 120},
	{71, 45, 124},
	{70, 50, 127},
	{69, 55, 130},
	{67, 60, 132},
	{66, 65, 134},
	{64, 70, 136},
	{62, 74, 137},
	{60, 79, 138},
	{58, 83, 139},
	{56, 87, 140},
	{54, 92, 141},
	{52, 96, 141},
	{50, 100, 142},
	{49, 104, 142},
	{47, 108, 142},
	{45, 112, 142},
	{44, 116, 142},
	{42, 119, 142},
	{41, 123, 142},
	{39, 127, 142},
	{38, 131, 142},
	{36, 135, 142},
	{35, 138, 141},
	{33, 142, 141},
	{32, 146, 140},
	{31, 150, 139},
	{31, 154, 138},
	{31, 157, 137},
	{31, 161, 135},
	{33, 165, 134},
	{35, 169, 132},
	{38, 172, 129},
	{42, 176, 127},
	{47, 180, 124},
	{53, 183, 121},
	{59, 187, 117},
	{66, 190, 113},
	{74, 194, 109},
	{82, 197, 105},
	{90, 200, 100},
	{99, 203, 95},
	{108, 206, 89},
	{118, 208, 84},
	{128, 211, 77},
	{138, 213, 71},
	{148, 216, 65},
	{159, 218, 58},
	{169, 220, 51},
	{180, 221, 44},
	{191, 223, 37},
	{202, 224, 31},
	{212, 226, 26},
	{223, 227, 24},
	{233, 228, 26},
	{243, 230, 30},
	{253, 231, 37},
};

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
