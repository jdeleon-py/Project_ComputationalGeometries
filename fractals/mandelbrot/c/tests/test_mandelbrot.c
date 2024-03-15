// MANDELBROT ENGINE TEST FILE
// - JAMES DELEON

#include "mandelbrot.h"

int main(int argc, char* argv[])
{
	// Complex** zplane = NULL;
	int iterations = 0;

	for(int y = 0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
			Site* pix = build_site(x, y);
			pix -> iterations = mandelbrot(pix);
			char sym = (pix -> iterations < MAX_ITERATIONS) ? '#' : ' ';
			printf("%c", sym);
			//printf("%d", iterations);
			destroy_site(pix);
		}
		printf("\n");
	}
	return 0;
}

/* END FILE */