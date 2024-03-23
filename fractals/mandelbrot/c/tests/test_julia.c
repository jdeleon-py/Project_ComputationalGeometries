// JULIA ENGINE TEST FILE
// - JAMES DELEON

#include "mandelbrot.h"

// modify DIM macro in mandelbrot.h to 100 for clearer visualization
int main(int argc, char* argv[])
{
	Dimensions* map = build_map(-1.5, 1.5, -1.5, 1.5);
	int iterations = 0;

	// seed value corresponds to constant c of the power iteration (z^2 + c)
	for(int y = 0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
			Site* pix = build_site(x, y);
			Complex seed = {-0.123, 0.745}; // Douady Rabbit Julia Set
			pix -> iterations = julia(map, pix, seed, 0);
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
