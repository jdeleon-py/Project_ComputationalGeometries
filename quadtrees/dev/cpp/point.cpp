// POINT (SITE) SOURCE FILE

#include "point.h"

Point::Point(int _x, int _y) : x{_x}, y{_y} {}

Point Point::operator+(int val) {return Point{x + val, y + val};}

Point Point::operator-(int val) {return Point{x - val, y - val};}

bool operator>(const Point& p1, const Point& p2) {return ((p1.x > p2.x) && (p1.y > p2.y)) ? true : false;}

bool operator<(const Point& p1, const Point& p2) {return ((p1.x < p2.x) && (p1.y < p2.y)) ? true : false;}

std::ostream& operator<<(std::ostream& ost, Point& p)
{
	ost << "Coordinates: (" << p.x << ", " << p.y << std::endl;
	return ost;
}