// CA CELL HEADER FILE
// - JAMES DELEON

#ifndef __CELL_H__
#define __CELL_H__

#include <iostream>
#include <random>

enum State {DEAD, ALIVE};

struct Color
{
	unsigned int R;
	unsigned int G;
	unsigned int B;
};

class Cell
{
public:
	Cell(bool init);

	inline int get_state() {return state;}
	void set_state(int new_state);

	friend std::ostream& operator<<(std::ostream& ost, Cell& cell);

	int neighbors = 0;

private:
	int define_state();
	Color define_color();

	int state;
	Color color;
	bool _init;
};

#endif

/* END FILE */
