// SECTOR (BOUNDARY) HEADER FILE

#ifndef __SECTOR_H__
#define __SECTOR_H__

#include <iostream>
#include "point.h"

class Sector
{
public:
	Sector(Point center, int radius);

	bool contains_point(Point point);

private:
	Point center;
	int radius;
}

#endif