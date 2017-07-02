#include "Shape2D.h"
#include "PointList.h"

Shape2D::Shape2D() : align(0)
{
}

Shape2D::~Shape2D()
{
}

bool Shape2D::setPoint(int x, int y)
{
	if (this->CPointList.addPoint(x, y)) {
		return true;
	}
	else {
		return false;
	}
}

bool Shape2D::delPoint(int x, int y)
{
	return false;
}


bool Shape2D::getPoints() const
{
	if ( this->CPointList.getPoints() ) {
		return true;
	}
	else {
		return false;
	}
}

PointListElement * Shape2D::getPoint() const
{
	return CPointList.getPoint(true);
}


bool Shape2D::setAlign(double newAlign)
{
	if (this->align = newAlign) {
		return true;
	}
	else {
		return false;
	}
}

double Shape2D::getAlign() const
{
	return this->align;
}

Shape2D Shape2D::box()
{
	Shape2D result;
	double minX = 0, maxX = 0, minY = 0, maxY = 0;
	PointList::Iterator It = this->CPointList.begin();
	
	while (It.getPointer() != nullptr) {

		//minX
		if (It.getPointer()->x < minX) {
			minX = It.getPointer()->x;
		}

		//maxX
		if (It.getPointer()->x > maxX) {
			maxX = It.getPointer()->x;
		}

		//minY
		if (It.getPointer()->y < minY) {
			minY = It.getPointer()->y;
		}

		//maxY
		if (It.getPointer()->y > maxY) {
			maxY = It.getPointer()->y;
		}

		++It;
	}

	// Punkte eintragen
	result.setPoint(minX, minY);
	result.setPoint(minX, maxY);
	result.setPoint(maxX, minY);
	result.setPoint(maxX, maxY);

	return result;
}
