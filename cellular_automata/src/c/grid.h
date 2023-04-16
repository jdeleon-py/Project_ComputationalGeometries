// GRID HEADER FILE

#ifndef __GRID_H__
#define __GRID_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cell.h"

#define DIM 256

typedef struct Cell** Grid;

Grid define_grid(bool init);
void destroy_grid(Grid cells);
int check_neighbors(Grid cells, int i, int j);

bool survival_rule(struct Cell* cell);
bool underpopulation_rule(struct Cell* cell);
bool overpopulation_rule(struct Cell* cell);
bool birth_rule(struct Cell* cell);

// eval_state function
Grid eval_state(Grid cells);

void print_grid();

#endif
