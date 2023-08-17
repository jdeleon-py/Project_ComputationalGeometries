// QUADTREE TEST FILE
// - JAMES DELEON

#include <stdio.h>
#include <stdbool.h>

//#include "site.h"
//#include "quadtree.h"

/*
int main(int argc, char* argv[])
{
	// a single site: 48 bytes
	return 0;
}
*/


// pixel
typedef struct Pixel
{
	//unsigned int x;
	//unsigned int y;
} Pixel;

// color
typedef struct Color
{
	unsigned int R;
	unsigned int G;
	unsigned int B;
} Color;

struct InnerStruct {
    int a;
    double b;
};

struct OuterStruct {
    int x;
    struct InnerStruct* inner;
};

typedef struct Site
{
	bool vor_node;

	Pixel* pixel;
	Color color;
	
	double min_distance;
	
	struct Site* closest_site;
} Site;

int main() {
	Site site;
    struct OuterStruct outer;
    struct InnerStruct inner;
    
    outer.x = 10;
    inner.a = 20;
    inner.b = 200000;
    outer.inner = &inner;

	printf("Size of size_t: %zu bytes\n", sizeof(size_t));


    size_t size = sizeof(site);

    printf("Size of OuterStruct: %zu bytes\n", size);
   
    size_t innerSize = sizeof(struct InnerStruct);
    printf("Size of InnerStruct: %zu bytes\n", innerSize);


    return 0;
}

