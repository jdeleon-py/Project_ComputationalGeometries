// SECTOR (BOUNDARY) SOURCE FILE

#include "sector.h"

Sector::Sector(Point cen, int rad) : center{cen}, radius{rad} {}

bool Sector::contains_point(Point point)
{
	// with overloads:
	return (point < (center + radius)) && (point > (center - radius)) ? true : false;

	// x_cond = (point.x < (center.x + radius)) && (point.x > (center.x - radius));
	// y cond = (point.y < (center.y + radius)) && (point.y > (center.y - radius));
	// return (x_cond && y_cond) ? true : false;
}