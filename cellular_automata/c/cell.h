// CELL HEADER FILE

#ifndef __CELL_H__
#define __CELL_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

enum State {DEAD, ALIVE};

typedef struct Color
{
	unsigned int R;
	unsigned int G;
	unsigned int B;
} Color;

typedef struct Cell
{
	int state;
	int neighbors;
	struct Color color;
	bool init;
} Cell;

int define_state(bool init);
struct Color define_color(struct Cell* cell);

void print_cell(Cell* cell);

#endif
