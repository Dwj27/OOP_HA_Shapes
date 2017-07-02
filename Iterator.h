#pragma once
#ifndef ITERATOR
#define ITERATOR
#include "PointList.h"

class Iterator
{
public:
	Iterator();
	~Iterator();
	PointListElement * getPointer() const;
	bool incr();
	bool reset();
private:
	PointListElement * pElement;
	PointListElement * pFirstElement;

};

#endif // !ITERATOR