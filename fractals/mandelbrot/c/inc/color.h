// COLOR HANDLING HEADER FILE
// - JAMES DELEON

#ifndef __COLOR_H__
#define __COLOR_H__

#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 50

typedef struct Color
{
	unsigned int R;
	unsigned int G;
	unsigned int B;
} Color;

// colormaps with range of 50 pixels
extern const Color map_magma[];
extern const Color map_inferno[];
extern const Color map_viridis[];

Color* build_color();
Color map_color_pixel(const Color map[], int iters);
void print_color(Color color);
void destroy_color(Color* color);

#endif

/* END FILE */