// MAIN FILE

#include <vector>
#include "cell.h"
#include "grid.h"

int main(void)
{
	std::cout << "Defining some cells..." << std::endl;
	std::vector<Cell> cells
	{
		Cell(true),
		Cell(true),
		Cell(true),
		Cell(true),
		Cell(true),
	};
	for(Cell cell: cells) {std::cout << cell << std::endl;}

	std::cout << "Defining a grid of cells..." << std::endl;
	Grid grid1;
	std::cout << grid1 << std::endl;
	std::cout << "Done." << std::endl;
}
