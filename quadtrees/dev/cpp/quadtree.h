// QUADTREE HEADER FILE

#ifndef __QUADTREE_H__
#define __QUADTREE_H__

#include <iostream>
#include <vector>
#include "point.h"

#define NODE_CAPACITY 4

struct QTNode
{
	bool divided;
	std::vector<Point> points;

	struct QuadTree* northwest;
	struct QuadTree* northeast;
	struct QuadTree* southwest;
	struct QuadTree* southeast;
};

class QuadTree
{
public:
	QuadTree();

	void subdivide();
	bool insert(Point point);

private:
	QTNode root;
}

#endif