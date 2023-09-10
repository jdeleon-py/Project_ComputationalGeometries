// CELL SOURCE FILE
// - JAMES DELEON

#include "cell.h"

Cell::Cell(bool init) : _init{init}
{
	state = define_state();
	color = define_color();
}

int Cell::define_state()
{
	if(_init == 1)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(0, 1);
		return dis(gen) ? ALIVE : DEAD;
	}
	else {return DEAD;}
}

void Cell::set_state(int new_state)
{
	state = new_state;
	color = define_color();
}

Color Cell::define_color()
{
	return state == ALIVE ? Color({255, 255, 255}) : Color({0, 0, 0});
}

std::ostream& operator<<(std::ostream& ost, Cell& cell)
{
	ost << "State: " << cell.state << ", Color: (" << cell.color.R << ", " << cell.color.G << ", " << cell.color.B << ")";
	return ost;
}
