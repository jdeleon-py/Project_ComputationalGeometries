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
	Cell get_cell(int i, int j);

	void check_neighbors(int i, int j, bool border);
	void eval_state();

	friend std::ostream& operator<<(std::ostream& ost, Grid& g);

private:
	bool survival_rule(int i, int j);
	bool underpopulation_rule(int i, int j);
	bool overpopulation_rule(int i, int j);
	bool birth_rule(int i, int j);

	GridType grid;
};

#endif
