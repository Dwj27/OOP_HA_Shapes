#include "Iterator.h"

Iterator::Iterator() : pElement()
{ 
}

Iterator::~Iterator()
{
}

PointListElement * Iterator::getPointer() const
{
	return this->pElement;
}

bool Iterator::incr()
{
	if (this->pElement = this->pElement->PNext) {
		return true;
	}
	else { 
		return false;
	}
}

bool Iterator::reset()
{
	this->pElement = this->pFirstElement;
	return false;
}
