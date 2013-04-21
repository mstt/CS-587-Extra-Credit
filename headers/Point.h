#ifndef __POINT_H_
#define __POINT_H_

#include "Actor.h"

/*
	Point
	======================
	Point in 2D space.
*/
struct Point
{
	int x;
	int y;

	Point(): x(0), y(0) {}
	Point(int x, int  y) : x(x), y(y) {}
};

#endif