// MANDELBROT ENGINE TEST FILE
// - JAMES DELEON

#include "mandelbrot.h"

// modify DIM macro in mandelbrot.h to 100 for clearer visualization
int main(int argc, char* argv[])
{
	Dimensions* map = build_map(-2, 1, -1.5, 1.5);

	for(int y = 0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
			Site* pix = build_site(x, y);
			pix -> iterations = mandelbrot(map, pix, 0);
			char sym = (pix -> iterations < MAX_ITERATIONS) ? '#' : ' ';
			printf("%c", sym);
			destroy_site(pix);
		}
		printf("\n");
	}
	destroy_map(map);
	return 0;
}

/* END FILE */
