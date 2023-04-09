// GRID HEADER FILE

#ifndef __GRID_H
#define __GRID_H

#include <iostream>
#include <vector>
#include "cell.h"

#define DIM 64

typedef std::vector<std::vector<Cell>> GridType;

class Grid
{
	public:
		Grid();
		~Grid();

		GridType define_grid(bool init);

		void check_neighbors(int i, int j, bool border);
		bool survival_rule(int i, int j);
		inline bool underpopulation_rule(int i, int j) {return ((grid[i][j].neighbors < 2) && (grid[i][j].get_state() == ALIVE)) ? ALIVE : DEAD;}
		inline bool overpopulation_rule(int i, int j)  {return ((grid[i][j].neighbors > 3) && (grid[i][j].get_state() == ALIVE)) ? ALIVE : DEAD;}
		inline bool birth_rule(int i, int j)           {return ((grid[i][j].neighbors == 3) && (grid[i][j].get_state() == DEAD)) ? ALIVE : DEAD;}

		void eval_state();

		friend std::ostream& operator<<(std::ostream& ost, Grid& g);

		GridType grid;
};

#endif
