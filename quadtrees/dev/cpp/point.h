// POINT (SITE) HEADER FILE

#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>

class Point
{
public:
	Point(int _x, int _y);

	Point operator+(int val);
	Point operator-(int val);

	friend std::ostream& operator<<(std::ostream& ost, Point& p);
	friend bool operator>(const Point& p1, const Point& p2);
	friend bool operator<(const Point& p1, const Point& p2);

private:
	int x;
	int y;
}

#endif