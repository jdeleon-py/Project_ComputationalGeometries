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
void destroy_grid(Grid grid);
int check_neighbors(Grid cells, int i, int j);

int survival_rule(Grid cells, int i, int j);
bool underpopulation_rule(struct Cell* cell, int i, int j);
bool overpopulation_rule(struct Cell* cell, int i, int j);
bool birth_rule(struct Cell* cell, int i, int j);

// eval_state function

void print_grid();

#endif
