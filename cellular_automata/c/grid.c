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
		cell_arr[i] -> color = define_color(cell_arr[i]);
	}
	return cell_arr;
}

void destory_grid(Grid cells)
{
	// freeing memory for 2D arr of cells
	for(int i = 0; i < DIM; i++)
	{
		free(cells[i]);
	}
	free(cells);
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

bool survival_rule(struct Cell* cell)
{
	bool neighbors_cond = (cell -> neighbors == 2) || (cell -> neighbors == 3);
	return (neighbors_cond && (cell -> state == ALIVE)) ? ALIVE : DEAD;
}

bool underpopulation_rule(struct Cell* cell)
{
	return ((cell -> neighbors < 2) && (cell -> state == ALIVE)) ? ALIVE : DEAD;
}

bool overpopulation_rule(struct Cell* cell)
{
	return ((cell -> neighbors > 3) && (cell -> state == ALIVE)) ? ALIVE : DEAD;
}

bool birth_rule(struct Cell* cell)
{
	return ((cell -> neighbors == 3) && (cell -> state == DEAD)) ? ALIVE : DEAD;
}

// eval_state function
Grid eval_state(Grid cells)
{
	// modify existing grid of cells
	Grid new_cells = define_grid(0);
	for(int row = 1; row < (DIM - 1); row++)
	{
		for(int col = 1; col < (DIM - 1); col++)
		{
			cells[row][col].neighbors = check_neighbors(cells, row, col);
			if(underpopulation_rule(cells[row][col]) == true)     {new_cells[row][col].state = DEAD;}
			else if(survival_rule(cells[row][col]) == true)       {new_cells[row][col].state = ALIVE;}
			else if(overpopulation_rule(cells[row][col]) == true) {new_cells[row][col].state = DEAD;}
			else if(birth_rule(cells[row][col]) == true)          {new_cells[row][col].state = ALIVE;}
		}
	}
	destory_grid(cells);
	return new_cells;
}

void print_grid();

