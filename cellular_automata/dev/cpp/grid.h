// GRID HEADER FILE

#ifndef __GRID_H
#define __GRID_H

#include <iostream>
#include <vector>
#include "cell.h"

#define DIM 512

typedef std::vector<std::vector<Cell>> GridType;

class Grid
{
	public:
		Grid();
		GridType define_grid(bool init);
		void check_neighbors(int i, int j, bool border);
		bool underpopulation_rule(int i, int j);
		bool survival_rule(int i, int j);
		bool overpopulation_rule(int i, int j);
		bool birth_rule(int i, int j);
		void eval_state();

		friend std::ostream& operator<<(std::ostream& ost, Grid& g);
	private:
		GridType grid;
};

#endif
