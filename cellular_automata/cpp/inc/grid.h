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

	// click cell operations
	void toggle_cell(int i, int j);
	inline void set_cell(int i, int j) {grid[i][j].set_state(1);}   // make cell alive
	inline void clear_cell(int i, int j) {grid[i][j].set_state(0);} // make cell dead

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
