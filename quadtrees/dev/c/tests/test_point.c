// POINT (SITE) TEST FILE
// - JAMES DELEON

#include "point.h"

#define POINT_N 5

int main(int argc, char* argv[])
{
	Point** arr = NULL;
	Point* p1 = NULL;
	Point* p2 = NULL;
	Point* p = NULL;

	printf("Allocating sites...\n");
	p1 = build_point(3, 5);
	p2 = build_point(8, 32);
	(p1 == NULL || p2 == NULL) ? printf("Allocation error.\n") : printf("Done.\n");

	printf("\nSites allocated. Printing...\n");
	print_point(p1);
	print_point(p2);

	printf("\nDeallocating sites...\n");
	destroy_point(p1);
	destroy_point(p2);
	printf("Done.\n\n");

	printf("Now dynamically building an array of sites...\n");
	arr = (Point**)malloc(POINT_N * sizeof(Point*));
	for(int i = 0; i < POINT_N; i++)
	{
		p = build_point(i, i * 2);
		arr[i] = p;
		(p == NULL) ? printf("Allocation error.\n") : printf("Done.\n");
	}

	printf("\nSites allocated. Printing...\n");;
	for(int i = 0; i < POINT_N; i++)
	{
		print_point(arr[i]);
	}

	printf("Deallocating sites...\n");
	for(int i = 0; i < POINT_N; i++)
	{
		destroy_point(arr[i]);
	}
	free(arr);
	printf("Done.\n\n");

	printf("Goodbye.\n");
	return 0;
}

