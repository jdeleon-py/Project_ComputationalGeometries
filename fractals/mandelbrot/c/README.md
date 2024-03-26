# Mandelbrot/Julia Visualization
These experiments demonstrate the simulation of Mandelbrot and Julia sets.

## Description and Theory
<!--This section describes the mathematical nature of fractal sets, exclusively pertaining to Mandelbrot sets but encompassing Julia sets as well.-->

### The Julia Set
### The Mandelbrot Set

## Algorithmic Methodology
<!--This section details the power iteration methodology necessary to measure the convergence tendancies for coordinates on a map.-->

### Power Iteration Algorithm

```math
z_{n + 1} = z_n^2 + c
```
where c is a complex constant.

```c
int mandelbrot(Dimensions* map, Site* pixel, int iter_offset)
{
	long double x_temp;
	Complex iter = {0, 0};

	pixel -> z.real = scale_x(map, pixel -> pix.x);
	pixel -> z.imag = scale_y(map, pixel -> pix.y);
	while(z_magnitude(iter) < 2 && pixel -> iterations < (MAX_ITERATIONS + iter_offset))
	{
		x_temp = pixel -> z.real + ((iter.real * iter.real) - (iter.imag * iter.imag));
		iter.imag = pixel -> z.imag + (2 * iter.real * iter.imag);
		iter.real = x_temp;
		pixel -> iterations++;
	}
	return pixel -> iterations;
}
```

```c
int julia(Dimensions* map, Site* pixel, Complex seed)
{
	Complex iter;
	long double x_temp, y_temp;
	
	iter.real = scale_x(map, pixel -> pix.x);
	iter.imag = scale_y(map, pixel -> pix.y);
	while(z_magnitude(iter) < 2 && pixel -> iterations < MAX_ITERATIONS)
	{
		x_temp = seed.real + (iter.real * iter.real) - (iter.imag * iter.imag);
		y_temp = seed.imag + (2 * iter.real * iter.imag);
		iter.real = x_temp;
		iter.imag = y_temp;
		pixel -> iterations++;
	}
	return pixel -> iterations;
}
```

```c
/*
 * quantizes x-range of map into WIDTH = DIM intervals
 * Ex. for the Mandelbrot root (-2, 1) -> (0, 511)
*/
long double scale_x(Dimensions* map, unsigned int pix_x)
{
	long double scale_factor;

	scale_factor = (long double)((WIDTH - 1) / (map -> x_max - map -> x_min));
	return (map -> x_min) + pix_x / scale_factor;
}

/*
 * quantizes y-range of map into HEIGHT = DIM intervals
 * Ex. for the Mandelbrot root (-1.5, 1.5) -> (0, 511)
*/
long double scale_y(Dimensions* map, unsigned int pix_y)
{
	long double scale_factor;
	
	scale_factor = (long double)((HEIGHT - 1) / (map -> y_max - map -> y_min));
	return (map -> y_min) + pix_y / scale_factor;
}
```

## Results
<!--This section displays outputs.-->

## Task List
<!--This section lists out certain tasks that have yet to be completed in the development of this project.-->
* [ ] Demonstrate using the Mariani-Silver Algorithm
* [ ] Demonstrate using algorithms involving Perturbation Theory
* [ ] Make a .gif animation that continuously zooms into the canvas up to a certain point
* [ ] Use an image compression technique (Huffman Code) to save encoded maps to a database
* [X] Modify the equation to visualize Julia Sets

## Resources
[Article: Julia and Mandelbrot Sets](https://e.math.cornell.edu/people/belk/dynamicalsystems/NotesJuliaMandelbrot.pdf)

[Coding Train: Mandelbrot Set](https://www.youtube.com/watch?v=6z7GQewK-Ks&pp=ygUZbWFuZGVsYnJvdCBzZXQgc2ltdWxhdGlvbg%3D%3D)

[Medium: Mariani-Silver Algorithm](https://ricomariani.medium.com/the-mariani-silver-algorithm-for-drawing-the-mandelbrot-set-a71e31bc20b6)

[3B1B: Julia Sets and Holomorphic Dynamics](https://www.youtube.com/watch?v=LqbZpur38nw&t=467s)
