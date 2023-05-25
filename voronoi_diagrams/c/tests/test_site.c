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
	}
	
	for(int i = 0; i < VOR_NUM; i++)
	{
		destroy_site(vor_nodes[i]);
	}
	return 0;
}
