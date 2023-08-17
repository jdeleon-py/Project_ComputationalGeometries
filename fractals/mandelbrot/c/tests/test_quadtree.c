// QUADTREE TEST FILE
// - JAMES DELEON

#include <time.h>
#include "point.h"
#include "quadtree.h"

#define WIDTH        512
#define HEIGHT       512

#define TEST_POINT_N 20

int generate_coordinate();

int main(int argc, char* argv[])
{
	srand(time(NULL));

	QuadTree* qt = NULL;
	Sector* sector = NULL;
	Point* center = NULL;

	center = build_point(WIDTH / 2, HEIGHT / 2);
	sector = build_sector(center, WIDTH / 2);
	qt = build_quadtree(sector);

	for(int i = 0; i < TEST_POINT_N; i++)
	{
		int x = generate_coordinate();
		int y = generate_coordinate();
		Point* p = build_point(x, y);
		insert(qt, p);
	}

	print_quadtree(qt);

	destroy_quadtree(qt);
	return 0;
}

int generate_coordinate()
{
	int lower = 0;
	int upper = WIDTH;

	int random_num = (rand() % (upper - lower + 1)) + lower;
	return random_num;
}

