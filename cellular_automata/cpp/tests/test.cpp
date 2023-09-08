// MAIN FILE

#include "cell.h"
#include "grid.h"
//#include "renderwindow.h"

int main(int argc, char* argv[])
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
	std::cout << "Done initializing..." << std::endl;

	//int running = 0;
	bool running = true;
	while(running == true)
	{
		grid1.eval_state();
		std::cout << grid1 << std::endl;
		//for(int i = 0; i < 5000000; i++);
		//running += 1;
	}
}
