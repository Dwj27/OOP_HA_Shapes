#pragma once
#ifndef SHAPE2D
#define SHAPE2D
#include "PointList.h"

class Shape2D
{
public:
	Shape2D();
	~Shape2D();
	bool setPoint(int x, int y);
	bool delPoint(int x, int y);
	bool getPoints() const;
	PointListElement * getPoint() const;
	bool setAlign(double newAlign);
	double getAlign() const;
	Shape2D box();

private:
	double align;
	PointList CPointList;
};

#endif // !SHAPE2D