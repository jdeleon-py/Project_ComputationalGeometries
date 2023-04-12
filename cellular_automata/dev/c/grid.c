// GRID SOURCE FILE

#include "grid.h"

Grid define_grid(bool init)
{
	Grid cell_arr;

	cell_arr = (Grid)malloc(DIM * sizeof(struct Cell*));
	for(int i = 0; i < DIM; i++)
	{
		cell_arr[i] = (struct Cell*)malloc(DIM * sizeof(struct Cell));
		cell_arr[i] -> state = (init == true) ? define_state(1) : define_state(0);
		cell_arr[i] = define_color(cell_arr[i]);
	}

	return cell_arr;
}

void destory_grid(Grid grid)
{
	// freeing memory for 2D arr of cells
	for(int i = 0; i < DIM; i++)
	{
		free(grid[i]);
	}
	free(grid);
}

int check_neighbors(Grid cells, int i, int j)
{
	int neighbor_count = 0;

	if(cells[i - 1][j - 1].state == ALIVE) {neighbor_count += 1;}
	if(cells[i - 1][j + 0].state == ALIVE) {neighbor_count += 1;}
	if(cells[i - 1][j + 1].state == ALIVE) {neighbor_count += 1;}
	if(cells[i + 0][j - 1].state == ALIVE) {neighbor_count += 1;}
	if(cells[i + 0][j + 1].state == ALIVE) {neighbor_count += 1;}
	if(cells[i + 1][j - 1].state == ALIVE) {neighbor_count += 1;}
	if(cells[i + 1][j + 0].state == ALIVE) {neighbor_count += 1;}
	if(cells[i + 1][j + 1].state == ALIVE) {neighbor_count += 1;}

	return neighbor_count;
}

int survival_rule(Grid cells, int i, int j)
{
	bool neighbors_cond = (cells[i][j].neighbors == 2) || (cells[i][j].neighbors == 3);
	return (neighbors_cond && (cells[i][j].state == ALIVE)) ? ALIVE : DEAD;
}

bool underpopulation_rule(struct Cell* cell, int i, int j);

bool overpopulation_rule(struct Cell* cell, int i, int j);

bool birth_rule(struct Cell* cell, int i, int j);

// eval_state function

void print_grid();

