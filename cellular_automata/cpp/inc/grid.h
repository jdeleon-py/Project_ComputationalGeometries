// CA GRID HEADER FILE
// - JAMES DELEON

#ifndef __GRID_H__
#define __GRID_H__

#include <iostream>
#include <vector>
#include "cell.h"

#define DIM 128

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
	bool survival_rule(Cell cell);
	bool underpopulation_rule(Cell cell);
	bool overpopulation_rule(Cell cell);
	bool birth_rule(Cell cell);

	GridType grid;
};

#endif

/* END FILE */
