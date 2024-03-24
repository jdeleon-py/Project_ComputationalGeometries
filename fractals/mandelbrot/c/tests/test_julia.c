// JULIA ENGINE TEST FILE
// - JAMES DELEON

#include "mandelbrot.h"

/*
 * NOTES FOR USER: 
 * - modify DIM macro in mandelbrot.h to 100 for clearer visualization
 * - input a complex seed value for rendering (Re(z), Im(z))
 * 
*/
int main(int argc, char* argv[])
{
	Dimensions* map = build_map(-1.5, 1.5, -1.5, 1.5);
	int iterations = 0;
	long double seed_re, seed_im;

	// user prompt for a complex seed value
	printf("Input a complex number 'Re(z) Im(z)' for rendering:\n");
	scanf("%Lf %Lf", &seed_re, &seed_im);

	// seed value corresponds to constant c of the power iteration (z^2 + c)
	for(int y = 0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
			Site* pix = build_site(x, y);
			Complex seed = {seed_re, seed_im}; // Douady Rabbit Julia Set
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
