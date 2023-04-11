// CELL SOURCE FILE

#include "cell.h"

int define_state(bool init)
{
	srand(time(NULL)); // seed generator with current time

	int state = (init == true) ? rand() % 2 : DEAD;
	return state;
}

struct Cell* define_color(struct Cell* cell)
{
	struct Color new_color;

	new_color.R = (cell -> state == ALIVE) * 255;
	new_color.G = (cell -> state == ALIVE) * 255;
	new_color.B = (cell -> state == ALIVE) * 255;

	cell -> color = new_color;
	return cell;
}

void print_cell() {}
