// CELL SOURCE FILE

#include "cell.h"

int define_state(bool init)
{
	return (init == true) ? rand() % 2 : DEAD;
}

struct Color define_color(Cell* cell)
{
	struct Color new_color;

	new_color.R = (cell -> state == ALIVE) * 255;
	new_color.G = (cell -> state == ALIVE) * 255;
	new_color.B = (cell -> state == ALIVE) * 255;

	return new_color;
}

void print_cell(Cell* cell)
{
	printf("State: %d, Color: (%d, %d, %d)\n", cell -> state, cell -> color.R, cell -> color.B, cell -> color.G);
}
