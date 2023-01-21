// GRID SOURCE FILE

#include "grid.h"

Grid::Grid() {grid = define_grid(true);}

GridType Grid::define_grid(bool init)
{
	GridType grid;
		for(int i = 0; i < DIM; i++)
		{
			std::vector<Cell> row;
			for(int j = 0; j < DIM; j++) {row.push_back(Cell(init));}
			grid.push_back(row);
		}
	return grid;
}

void Grid::check_neighbors(int i, int j, bool border)
{
	if(border == 1)
	{
		if(grid[i - 1][j - 1].get_state() == ALIVE) {grid[i][j].neighbors += 1;}
		if(grid[i - 1][j + 0].get_state() == ALIVE) {grid[i][j].neighbors += 1;}
		if(grid[i - 1][j + 1].get_state() == ALIVE) {grid[i][j].neighbors += 1;}
		if(grid[i + 0][j - 1].get_state() == ALIVE) {grid[i][j].neighbors += 1;}
		if(grid[i + 0][j + 1].get_state() == ALIVE) {grid[i][j].neighbors += 1;}
		if(grid[i + 1][j - 1].get_state() == ALIVE) {grid[i][j].neighbors += 1;}
		if(grid[i + 1][j + 0].get_state() == ALIVE) {grid[i][j].neighbors += 1;}
		if(grid[i + 1][j + 1].get_state() == ALIVE) {grid[i][j].neighbors += 1;}
	}
}

bool Grid::underpopulation_rule(int i, int j)
{
	return ((grid[i][j].neighbors < 2) && (grid[i][j].get_state() == ALIVE)) ? ALIVE : DEAD;
}

bool Grid::survival_rule(int i, int j)
{
	bool neighbors_cond = ((grid[i][j].neighbors == 2) || (grid[i][j].neighbors == 3));
	return (neighbors_cond && (grid[i][j].get_state() == ALIVE)) ? ALIVE : DEAD;
}

bool Grid::overpopulation_rule(int i, int j)
{
	return ((grid[i][j].neighbors > 3) && (grid[i][j].get_state() == ALIVE)) ? ALIVE : DEAD;
}

bool Grid::birth_rule(int i, int j)
{
	return ((grid[i][j].neighbors == 3) && (grid[i][j].get_state() == DEAD)) ? ALIVE : DEAD;
}

void Grid::eval_state()
{
	// modify the already existing grid
	GridType grid_copy = define_grid(false);
	for(int row = 1; row <= (DIM - 1); row++)
	{
		for(int col = 1; col <= (DIM - 1); col++)
		{
			check_neighbors(row, col, 1);
			if(underpopulation_rule(row, col) == true)     {grid_copy[row][col].set_state(DEAD);}
			else if(survival_rule(row, col) == true)       {grid_copy[row][col].set_state(ALIVE);}
			else if(overpopulation_rule(row, col) == true) {grid_copy[row][col].set_state(DEAD);}
			else if(birth_rule(row, col) == true)          {grid_copy[row][col].set_state(ALIVE);}
		}
	}
	grid = grid_copy;
}

std::ostream& operator<<(std::ostream& ost, Grid& g)
{
	for(int i = 0; i < DIM; i++)
	{
		for(int j = 0; j < DIM; j++) {ost << g.grid[i][j].get_state() << ' ';}
		ost << std::endl;
	}
	return ost;
}
