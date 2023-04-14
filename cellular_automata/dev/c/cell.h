// CELL HEADER FILE

#ifndef __CELL_H__
#define __CELL_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

enum State {DEAD, ALIVE};

struct Color
{
	unsigned int R;
	unsigned int G;
	unsigned int B;
};

struct Cell
{
	int state;
	int neighbors;
	struct Color color;
	bool init;
};

int define_state(bool init);
struct Color define_color(struct Cell* cell);

void print_cell();

#endif
