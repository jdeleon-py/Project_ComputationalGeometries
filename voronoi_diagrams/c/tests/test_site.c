// VORONOI PIXEL (SITE) TEST FILE

#include "site.h"

#define VOR_NUM 10

int main(int argc, char* argv[])
{
	Site* vor_nodes[VOR_NUM];
	for(int i = 0; i < VOR_NUM; i++)
	{
		vor_nodes[i] = build_site(10 + i, 20 + i, true);
		print_site(vor_nodes[i]);
		destroy_site(vor_nodes[i]);
	}
	
	Site* test_corners[4];
	for(int i = 0; i < 4; i++)
	{
		test_corners[i] = build_site(i * 2, i * 3, false);
		print_site(test_corners[i]);
		destroy_site(test_corners[i]);
	}

	return 0;
}
